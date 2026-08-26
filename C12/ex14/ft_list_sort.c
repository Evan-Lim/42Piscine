/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:12:13 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 12:33:38 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	void	*tmp;
	int		swapped;

	if (!begin_list || !*begin_list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *begin_list;
		while (curr && curr->next)
		{
			if ((*cmp)(curr->data, curr->next->data) > 0)
			{
				tmp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = tmp;
				swapped = 1;
			}
			curr = curr->next;
		}
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int		i;

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
	char	*strs[] = {"cherry", "apple", "date", "banana"};
	t_list	*list;

	list = ft_list_push_strs(4, strs);
	printf("Before sorting: ");
	print_list(list);
	ft_list_sort(&list, &cmp_strs);
	printf("After sorting: ");
	print_list(list);
	return (0);
}
*/
