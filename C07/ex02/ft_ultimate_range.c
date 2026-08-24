/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:28:26 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/17 09:31:56 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	i;

	length = max - min;
	i = 0;
	if (min >= max)
	{
		(*range) = NULL;
		return (0);
	}
	(*range) = (int *)malloc(sizeof(int) * length);
	if ((*range) == NULL)
		return (-1);
	while (i < length)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (length);
}

/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*range;

	i = 0;
	printf("%d\n", ft_ultimate_range(&range, 3, 7));
	printf("\n");
	while (i < 4)
		printf("%d\n", range[i++]);
	free(range);
}
*/
