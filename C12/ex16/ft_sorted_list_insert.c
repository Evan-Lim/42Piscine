/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:15:42 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:19:48 by elim-hon         ###   ########.fr       */
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_node;
	t_list	*curr;

	new_node = ft_create_elem(data);
	if (!new_node || !begin_list)
		return ;
	if (!*begin_list || (*cmp)(data, (*begin_list)->data) < 0)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
		return ;
	}
	curr = *begin_list;
	while (curr->next && (*cmp)(data, curr->next->data) >= 0)
		curr = curr->next;
	new_node->next = curr->next;
	curr->next = new_node;
}

/*
#include <stdio.h>
#include <string.h>

int	cmp_strs(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
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
	t_list	*list;

	list = NULL;
	printf("--- Testing ex16: ft_sorted_list_insert ---\n");
	// Insert items in mixed order
	ft_sorted_list_insert(&list, "cherry", &cmp_strs);
	ft_sorted_list_insert(&list, "apple", &cmp_strs);
	ft_sorted_list_insert(&list, "date", &cmp_strs);
	ft_sorted_list_insert(&list, "banana", &cmp_strs);
	printf("Result: ");
	print_list(list);
	return (0);
}
*/
