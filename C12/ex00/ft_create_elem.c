/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:49:31 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 08:50:31 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_create_elem("Hello World!");
	if (node)
	{
		printf("%s\n", (char *)node->data);
		printf("%p\n", (void *)node->next);
	}
	free(node);
	return (0);
}
*/
