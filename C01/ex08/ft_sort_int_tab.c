/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 10:57:02 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/09 12:10:06 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	not_sorted;
	int	temp;

	i = 0;
	not_sorted = 1;
	temp = 0;
	while (not_sorted == 1)
	{
		not_sorted = 0;
		i = 0;
		while (i < size)
		{
			if ((i != (size - 1)) && (tab[i] > tab[i + 1]))
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				not_sorted = 1;
			}
			i++;
		}
	}
}
