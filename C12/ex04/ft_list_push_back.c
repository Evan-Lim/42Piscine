/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:04:08 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 14:21:06 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
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
*/

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*current;

	if (!begin_list)
		return ;
	new_node = ft_create_elem(data);
	if (!new_node)
		return ;
	if (!(*begin_list))
	{
		*begin_list = new_node;
		return ;
	}
	current = *begin_list;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*list;
	t_list	*current;

	list = NULL;
	ft_list_push_back(&list, "1st");
	ft_list_push_back(&list, "2nd");
	ft_list_push_back(&list, "3rd");
	current = list;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->data);
		current = current->next;
	}
	return (0);
}
*/
