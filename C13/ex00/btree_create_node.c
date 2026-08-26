/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:34:48 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:36:18 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_node;

	new_node = (t_btree *)malloc(sizeof(t_btree));
	if (!new_node)
		return (NULL);
	new_node->item = item;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
