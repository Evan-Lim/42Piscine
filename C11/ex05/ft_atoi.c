/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:22:00 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 12:31:21 by elim-hon         ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign * (store_num(str, i)));
}
