/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 07:20:38 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:25:24 by elim-hon         ###   ########.fr       */
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	t_list	*curr;
	t_list	*next;

	if (!begin_list1)
		return ;
	curr = begin_list2;
	while (curr)
	{
		next = curr->next;
		ft_sorted_list_insert(begin_list1, curr->data, cmp);
		curr = next;
	}
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
	t_list *list1 = NULL;
	t_list *list2 = NULL;

	// Populate list1 in sorted order
	ft_sorted_list_insert(&list1, "apple", &cmp_strs);
	ft_sorted_list_insert(&list1, "date", &cmp_strs);

	// Populate list2 in sorted order
	ft_sorted_list_insert(&list2, "banana", &cmp_strs);
	ft_sorted_list_insert(&list2, "elderberry", &cmp_strs);

	printf("--- Testing ex17: ft_sorted_list_merge ---\n");
	printf("List 1 before merge: ");
	print_list(list1);
	printf("List 2 before merge: ");
	print_list(list2);

	ft_sorted_list_merge(&list1, list2, &cmp_strs);

	printf("Merged List:         ");
	print_list(list1);

	return (0);
}
*/
