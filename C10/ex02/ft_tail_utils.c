/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 07:29:59 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 07:31:24 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

void	ft_display_error(char *prog_name, char *file_name)
{
	char	*base;

	base = basename(prog_name);
	write(2, base, strlen(base));
	write(2, ": ", 2);
	write(2, file_name, strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	print_tail(char *buf, int total_bytes, int byte_count)
{
	int	i;

	if (total_bytes <= byte_count)
		write(1, buf, total_bytes);
	else
	{
		i = 0;
		while (i < byte_count)
		{
			write(1, &buf[(total_bytes + i) % byte_count], 1);
			i++;
		}
	}
}
