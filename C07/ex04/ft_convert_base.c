/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 14:39:19 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/17 08:06:46 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str);
int			check_base(char *base);
int			ft_atoi_base(char *str, char *base);

int	get_nbr_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

long	negative_value(char *res, long n)
{
	if (n < 0)
	{
		res[0] = '-';
		return (-n);
	}
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	n;
	int		base_to_len;
	int		str_len;
	char	*res;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	base_to_len = ft_strlen(base_to);
	str_len = get_nbr_len(n, base_to_len);
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	res[str_len] = '\0';
	if (n == 0)
		res[0] = base_to[0];
	n = negative_value(res, n);
	while (n > 0)
	{
		res[--str_len] = base_to[n % base_to_len];
		n /= base_to_len;
	}
	return (res);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*result;

	if (argc == 4)
	{
		result = ft_convert_base(argv[1], argv[2], argv[3]);
		if (result)
		{
			printf("%s\n", result);
			free(result);
		}
	}
	return (0);
}
*/
