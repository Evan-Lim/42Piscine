/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:24:01 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 14:50:15 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	t_list	*new_node;
	int	i;

	if (size <= 0 || !strs)
		return (0);
	head = 0;
	i = 0;	 
	while (i < size)
	{
		new_node = ft_create_elem(strs[i]);
		if (!new_node)
			return (head);
		new_node->next = head;
		head = new_node;
		i++;
	}
	return (head);
}

/*
#include <stdlib.h>
#include <stdio.h>

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

void	print_list(t_list *head)
{
	while (head)
	{
		printf("[%s] -> ", (char *)head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	char	*strs[] = {"apple", "banana", "cherry", "date"};
	int	size = 4;

	t_list	*list = ft_list_push_strs(size, strs);
	print_list(list);
	return (0);
}
*/
