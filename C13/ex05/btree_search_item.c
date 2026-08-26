/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:45:46 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:46:03 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void	*result;

	if (!root || !cmpf)
		return (NULL);
	// 1. Search Left
	result = btree_search_item(root->left, data_ref, cmpf);
	if (result)
		return (result);
	// 2. Check Root
	if ((*cmpf)(data_ref, root->item) == 0)
		return (root->item);
	// 3. Search Right
	return (btree_search_item(root->right, data_ref, cmpf));
}
