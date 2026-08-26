/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 07:50:55 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 08:02:36 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
*/

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!begin_list || !*begin_list)
		return ;
	prev = 0;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
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
	char	*strs[] = {"A", "B", "C", "D"};
	t_list	*list;

	list = ft_list_push_strs(4, strs);
	printf("Before: ");
	print_list(list);
	ft_list_reverse(&list);
	printf("After: ");
	print_list(list);
	return (0);
}
*/
