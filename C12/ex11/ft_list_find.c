/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 10:00:13 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 10:09:46 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			return (current);
		current = current->next;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	cmp_strs(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	main(void)
{
	t_list	node3;
	t_list	node2;
	t_list	node1;
	char	*search_1;
	char	*search_2;
	t_list	*found_1;
	t_list	*found_2;

	node3 = {NULL, "cherry"};
	node2 = {&node3, "banana"};
	node1 = {&node2, "apple"};
	search_1 = "banana";
	search_2 = "dragonfruit";
	found_1 = ft_list_find(&node1, search_1, &cmp_strs);
	found_2 = ft_list_find(&node1, search_2, &cmp_strs);
	if (found_1)
		printf("Found %s at node address: %p\n", (char *)found_1->data,
			(void *)found_1);
	else
		printf("%s not found\n", search_1);
	if (found_2)
		printf("Found %s at node address: %p\n", (char *)found_2->data,
			(void *)found_2);
	else
		printf("%s not found\n", search_2);
	return (0);
}
*/
