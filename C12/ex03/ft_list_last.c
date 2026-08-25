/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:46:55 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 14:21:36 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	int		i;
	t_list	*current;

	if (!begin_list)
		return (0);
	i = 0;
	current = begin_list;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (current);
}

/*
#include <stdio.h>
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (!begin_list)
		return ;
	new_node = ft_create_elem(data);
	if (!new_node)
		return ;
	new_node->next = *begin_list;
	*begin_list = new_node;
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, "3rd");
	ft_list_push_front(&list, "2nd");
	ft_list_push_front(&list, "1st");
	printf("%s\n", (char *)ft_list_last(list)->data);
	return (0);
}
*/
