/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:10:18 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 11:53:54 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		if (free_fct)
			(*free_fct)(tmp->data);
		free(tmp);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			if (free_fct)
				(*free_fct)(tmp->data);
			free(tmp);
		}
		else
			curr = curr->next;
	}
}

/*
#include <stdio.h>
#include <string.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		if (free_fct && begin_list->data)
			(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}

int	cmp_strs(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

void	free_data(void *data)
{
	free(data);
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
	t_list	*n4;
	t_list	*n3;
	t_list	*n2;
	t_list	*n1;
	t_list	*head;

	n4 = malloc(sizeof(t_list));
	n3 = malloc(sizeof(t_list));
	n2 = malloc(sizeof(t_list));
	n1 = malloc(sizeof(t_list));
	head = n1;
	n1->data = strdup("REMOVE");
	n1->next = n2;
	n2->data = strdup("KEEP");
	n2->next = n3;
	n3->data = strdup("REMOVE");
	n3->next = n4;
	n4->data = strdup("REMOVE");
	n4->next = NULL;
	printf("Before removal: ");
	print_list(head);
	ft_list_remove_if(&head, "REMOVE", &cmp_strs, &free_data);
	printf("After removal: ");
	print_list(head);
	ft_list_clear(head, &free_data);
	return (0);
}
*/
