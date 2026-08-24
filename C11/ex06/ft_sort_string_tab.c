/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:00:16 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 16:23:34 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	uc[2];

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	uc[0] = (unsigned char)s1[i];
	uc[1] = (unsigned char)s2[i];
	return (uc[0] - uc[1]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		not_sorted;
	int		length;
	char	*temp;

	not_sorted = 1;
	length = ft_tablen(tab);
	while (not_sorted)
	{
		not_sorted = 0;
		i = 0;
		while (i < length - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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

/*
#include <unistd.h>

void	write_param(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j])
		write(1, &argv[i][j++], 1);
	write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		ft_sort_string_tab(argv + 1);
		while (i < argc)
			write_param(argv, i++);
	}
	return (0);
}
*/
