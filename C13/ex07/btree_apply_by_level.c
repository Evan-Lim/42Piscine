/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:48:39 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:49:29 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

// 1. Helper to calculate tree height
static int	get_height(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = get_height(root->left);
	right = get_height(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

// 2. Helper to apply function at a target level
static void	apply_at_level(t_btree *root, int current_level, int target_level,
		int *first_flags, void (*applyf)(void *, int, int))
{
	if (!root)
		return ;
	if (current_level == target_level)
	{
		(*applyf)(root->item, current_level, first_flags[current_level]);
		first_flags[current_level] = 0;
			// Next nodes at this level are not first
		return ;
	}
	apply_at_level(root->left, current_level + 1, target_level, first_flags,
		applyf);
	apply_at_level(root->right, current_level + 1, target_level, first_flags,
		applyf);
}

// 3. Main function
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first))
{
	int	height;
	int	*first_flags;
	int	i;

	if (!root || !applyf)
		return ;
	height = get_height(root);
	first_flags = (int *)malloc(sizeof(int) * height);
	if (!first_flags)
		return ;
	i = 0;
	while (i < height)
	{
		first_flags[i] = 1; // Set first node flag to true for each level
		i++;
	}
	i = 0;
	while (i < height)
	{
		apply_at_level(root, 0, i, first_flags, applyf);
		i++;
	}
	free(first_flags);
}
