/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 08:26:09 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/10 17:51:54 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_printnum(int n, int a, int x, int arr_out[]);
void	ft_printnum_final(int n_f, int i_f, int arr_f[]);

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n > 0 && n < 10)
	{
		ft_printnum(n, 0, 0, arr);
	}
}

void	ft_printnum(int n, int a, int x, int arr_out[])
{
	int		i;
	int		j;

	if (x == n)
	{
		i = 0;
		ft_printnum_final(n, i, arr_out);
		return ;
	}
	j = a;
	while (j <= (9 - (n - x - 1)))
	{
		arr_out[x] = j;
		ft_printnum(n, j + 1, x + 1, arr_out);
		j++;
	}
}

void	ft_printnum_final(int n_f, int i_f, int arr_f[])
{
	char	char_write;

	while (i_f < n_f)
	{
		char_write = arr_f[i_f] + '0';
		write(1, &char_write, 1);
		i_f++;
	}
	if (arr_f[0] != 10 - n_f)
	{
		write(1, ", ", 2);
	}
}

int	main(void)
{
	ft_print_combn(4);
}
