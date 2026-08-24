/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:17:35 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/17 09:25:09 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	*array;
	int	i;

	length = max - min;
	i = 0;
	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * length);
	if (array == NULL)
		return (NULL);
	while (i < length)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*array;

	i = 0;
	array = ft_range(3, 7);
	while (i < 4)
		printf("%d\n", array[i++]);
	free(array);
	return (0);
}
*/
