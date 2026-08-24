/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:58:34 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/13 15:40:30 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_param(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j] != '\0')
		write(1, &argv[i][j++], 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	uc[2];

	i = 0;
	while ((s1[i] != '\0') && (s1[i] == s2[i]))
		i++;
	uc[0] = (unsigned char)s1[i];
	uc[1] = (unsigned char)s2[i];
	return (uc[0] - uc[1]);
}

void	ft_sort_string_tab(char **tab, int size)
{
	int		i;
	int		not_sorted;
	char	*temp;

	not_sorted = 1;
	while (not_sorted == 1)
	{
		not_sorted = 0;
		i = 1;
		while (i < (size - 1))
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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		ft_sort_string_tab(argv, argc);
		while (i < argc)
		{
			write_param(argv, i);
			i++;
		}
	}
	return (0);
}
