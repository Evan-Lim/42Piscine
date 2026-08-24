/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:24:19 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/06 13:49:07 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_printnum(char i_p, char j_p, char k_p);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				ft_printnum(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_printnum(char i_p, char j_p, char k_p)
{
	write(1, &i_p, 1);
	write(1, &j_p, 1);
	write(1, &k_p, 1);
	if (!(i_p == '7' && j_p == '8' && k_p == '9'))
	{
		write(1, ", ", 2);
	}
}
