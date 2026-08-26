/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:47:34 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:47:46 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_height;
	int	right_height;

	if (!root)
		return (0);
	left_height = btree_level_count(root->left);
	right_height = btree_level_count(root->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
