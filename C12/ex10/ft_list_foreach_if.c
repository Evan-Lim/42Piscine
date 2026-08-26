/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 09:40:56 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 09:58:10 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			(*f)(current->data);
		current = current->next;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	cmp_strs(void *a, void *b)
{
	return (strcmp((char *)a, (char *)b));
}

void	action_on_match(void *data)
{
	printf("-> Action triggered for target match: %s\n", (char *)data);
}

int	main(void)
{
	t_list	node4;
	t_list	node3;
	t_list	node2;
	t_list	node1;
	char	*target;

	node4 = {NULL, "apple"};
	node3 = {&node4, "banana"};
	node2 = {&node3, "apple"};
	node1 = {&node2, "cherry"};
	target = "apple";
	printf("Searching list for %s to apply action:\n", target);
	ft_list_foreach_if(&node1, &action_on_match, target, &cmp_strs);
	return (0);
}
*/
