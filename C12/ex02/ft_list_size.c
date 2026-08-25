/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 09:58:48 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 10:30:57 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*current;

	i = 0;
	current = begin_list;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
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
	printf("%d\n", ft_list_size(list));
	ft_list_push_front(&list, "3rd");
	ft_list_push_front(&list, "2nd");
	ft_list_push_front(&list, "1st");
	printf("%d\n", ft_list_size(list));
	return (0);
}
*/
