/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:25:36 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 07:45:15 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	if ((base_system == 0) || (base_system == 1))
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

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			base_system;

	n = nbr;
	base_system = ft_strlen(base);
	if (edge_cases(base_system, base) == 1)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > (base_system - 1))
		ft_putnbr_base((n / base_system), base);
	write(1, &base[n % base_system], 1);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr_base(42, argv[1]);
}
*/
