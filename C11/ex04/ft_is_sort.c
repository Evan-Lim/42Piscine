/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:39:47 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 12:16:07 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	compare(int a, int b)
{
	return (b - a);
}
*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	i = 0;
	ascending = 1;
	descending = 1;
	while (i < (length - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			ascending = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			descending = 0;
		i++;
	}
	return (ascending || descending);
}

/*
#include <stdio.h>
int	main(void)
{
	int	arr_asc[] = {-1, 0, 1, 1, 2, 5, 7};
	int	arr[] = {-1, -2, 1, 3, 5, 7};
	int	arr_dsc[] = {8, 4, 2, 0, -2};
	(void)arr_asc;
	(void)arr_dsc;
	printf("%d\n", ft_is_sort(arr,  6, &compare));
}
*/
