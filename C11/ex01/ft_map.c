/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:00:46 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 10:58:49 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
int	power_two(int num)
{
	return (num * num);
}
*/

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[5] = {0, 1, 4, 5, 7};
	int	i;

	i = 0;
	while (i < 5)
		printf("%d\n", ft_map(tab, 5, &power_two)[i++]);
}
*/
