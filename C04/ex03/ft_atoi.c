/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 11:26:16 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/14 13:51:57 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	store_num(char *str, int i)
{
	int	num;

	num = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = ((10 * num) + (str[i] - '0'));
		i++;
	}
	return (num);
}

int	sign_negative(int negative)
{
	if ((negative % 2) != 0)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negative;
	int	sign;

	i = 0;
	negative = 0;
	sign = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	sign = sign_negative(negative);
	return (sign * (store_num(str, i)));
}


#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d", ft_atoi(argv[1]));
	}
}

