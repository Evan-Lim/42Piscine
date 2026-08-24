/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:47:10 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 08:08:52 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	edge_cases(int base_system, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base_system < 2)
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-') || (base[i] <= 32)
			|| (base[i] == 127))
			return (1);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	store_num(char *str, char *base, int i, int base_system)
{
	int	num;
	int	j;

	num = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while ((base[j] != '\0') && (base[j] != str[i]))
			j++;
		if (base[j] == '\0')
			break ;
		num = (base_system * num) + j;
		i++;
	}
	return (num);
}

int	sign_negative(int negative)
{
	if (negative % 2 != 0)
		return (-1);
	else
		return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negative;
	int	sign;
	int	base_system;

	base_system = ft_strlen(base);
	if (edge_cases(base_system, base) == 1)
		return (0);
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
	return (sign * (store_num(str, base, i, base_system)));
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", ft_atoi_base(argv[1], argv[2]));
}
*/
