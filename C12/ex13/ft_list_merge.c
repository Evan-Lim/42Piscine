/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 11:55:42 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 12:09:12 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curr;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	curr = *begin_list1;
	while (curr->next)
		curr = curr->next;
	curr->next = begin_list2;
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
	char	*strs1[] = {"One", "Two"};
	char	*strs2[] = {"Three", "Four"};
	t_list	*list1 = ft_list_push_strs(2, strs1);
	t_list	*list2 = ft_list_push_strs(2, strs2);

	printf("List 1 before merge: ");
	print_list(list1);
	printf("List 2 before merge: ");
	print_list(list2);
	ft_list_merge(&list1, list2);
	printf("Merged List 1: ");
	print_list(list1);
	return (0);
}
*/
