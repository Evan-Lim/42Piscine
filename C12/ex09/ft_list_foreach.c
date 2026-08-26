/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:04:21 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/26 09:38:56 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if (f)
			(*f)(current->data);
		current = current->next;
	}
}

/*
#include <stdio.h>

void	print_element(void *data)
{
	printf("[%s] ", (char *)data);
}

void	uppercase_first(void *data)
{
	char	*str = (char *)data;
	if (str && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
}

int	main(void)
{
	char	str1[] = "apple";
	char	str2[] = "banana";
	char	str3[] = "cherry";

	t_list	node3 = {NULL, str3};
	t_list	node2 = {&node3, str2};
	t_list	node1 = {&node2, str1};
	printf("Original: ");
	ft_list_foreach(&node1, &print_element);
	printf("\n");
	ft_list_foreach(&node1, &uppercase_first);
	printf("Modified: ");
	ft_list_foreach(&node1, &print_element);
	printf("\n");
	return (0);
}
*/
