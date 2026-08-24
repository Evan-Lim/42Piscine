/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:04:46 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 16:50:29 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	num;

	i = nb - 1;
	num = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i >= 1)
	{
		num = num * i;
		i--;
	}
	return (num);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(-1));
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(2));
	printf("%d\n", ft_iterative_factorial(7));
}
*/
