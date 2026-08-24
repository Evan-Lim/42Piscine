/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:19:52 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 14:34:28 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);
int	ft_plus(int a, int b);
int	ft_minus(int a, int b);
int	ft_multiply(int a, int b);
int	ft_divide(int a, int b);
int	ft_modulo(int a, int b);

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_calc(int a, int b, int (*f)(int, int))
{
	return ((*f)(a, b));
}

int	ft_operation(int a, int b, char operator)
{
	int	number;
	
	number = 0;
	if (operator == '+')
		number = ft_calc(a, b, &ft_plus);
	else if (operator == '-')
		number = ft_calc(a, b, &ft_minus);
	else if (operator == '*')
		number = ft_calc(a, b, &ft_multiply);
	else if (operator == '/')
		number = ft_calc(a, b, &ft_divide);
	else if (operator == '/')
		number = ft_calc(a, b, &ft_modulo);
	return (number);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	char	operator;
	int	number;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		operator = argv[2][0];
		if (b == 0 && operator == '/')
		{
			write(1, "Stop : division by zero", 23);
			return (0);
		}
		if (b == 0 && operator == '%')
		{
			write(1, "Stop : modulo by zero", 21);
			return (0);
		}
		number = ft_operation(a, b, operator);
		ft_putnbr(number);
	}
	return (0);
}
