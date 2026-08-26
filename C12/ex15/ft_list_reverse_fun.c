/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 12:34:23 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/27 07:14:25 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size_internal(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*ft_list_at_internal(t_list *begin_list, unsigned int n)
{
	while (begin_list && n > 0)
	{
		begin_list = begin_list->next;
		n--;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	t_list	*node_left;
	t_list	*node_right;
	void	*tmp;

	size = ft_list_size_internal(begin_list);
	i = 0;
	while (i < size / 2)
	{
		node_left = ft_list_at_internal(begin_list, i);
		node_right = ft_list_at_internal(begin_list, size - 1 - i);
		tmp = node_left->data;
		node_left->data = node_right->data;
		node_right->data = tmp;
		i++;
	}
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
	char	*strs[] = {"A", "B", "C", "D", "E"};

	t_list *list = ft_list_push_strs(5, strs); // E -> D -> C -> B -> A
	printf("Before reverse: ");
	print_list(list);
	ft_list_reverse_fun(list);
	printf("After reverse:  ");
	print_list(list);
	return (0);
}
*/
