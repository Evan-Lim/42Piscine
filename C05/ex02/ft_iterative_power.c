/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:55:15 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 17:14:58 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	num = nb;
	if ((nb == 0) && (power == 0))
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		num = num * nb;
		power--;
	}
	return (num);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(0, -1));
	printf("%d\n", ft_iterative_power(0, 1));
	printf("%d\n", ft_iterative_power(1, 1));
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d\n", ft_iterative_power(3, 4));
}
*/
