/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:15:31 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 17:20:56 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0) && (power == 0))
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_recursive_power(0, 0));
	printf("%d\n", ft_recursive_power(0, -1));
	printf("%d\n", ft_recursive_power(0, 1));
	printf("%d\n", ft_recursive_power(1, 1));
	printf("%d\n", ft_recursive_power(2, 0));
	printf("%d\n", ft_recursive_power(2, 2));
	printf("%d\n", ft_recursive_power(3, 4));
}
*/
