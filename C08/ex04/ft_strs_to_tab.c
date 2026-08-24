/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:46:32 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/20 08:27:30 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_tab(t_stock_str *array, int i)
{
	while (--i >= 0)
		free(array[i].copy);
	free(array);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;

	if (ac < 0 || !av)
		return (NULL);
	array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
			return (free_tab(array, i), NULL);
	}
	array[i] = (t_stock_str){0, 0, 0};
	return (array);
}

// FROM HERE ONWARDS; TESTING PURPOSES

// INCLUDE IN FT_STOCK_STR.H FILE (CREATE IT)

/*
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}	t_stock_str;

#endif
*/

// END OF FT_STOCK_STR.H FILE (REMOVE THE CODE ABOVE AFTER CREATION)

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	ft_putchar(c);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int	i;

	tab = ft_strs_to_tab(argc - 1, argv + 1);
	if (!tab)
		return (1);
	ft_show_tab(tab);
	i = 0;
	while (tab[i].str != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}
*/
