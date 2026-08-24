/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 07:38:24 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/24 07:38:57 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void	ft_tail_stream(int fd, int byte_count)
{
	char	*buf;
	char	ch;
	int		total_bytes;
	int		i;

	if (byte_count <= 0)
		return ;
	buf = malloc(sizeof(char) * byte_count);
	if (!buf)
		return ;
	total_bytes = 0;
	while (read(fd, &ch, 1) > 0)
	{
		buf[total_bytes % byte_count] = ch;
		total_bytes++;
	}
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
	free(buf);
}

int	main(int argc, char **argv)
{
	int	byte_count;
	int	file_idx;
	int	fd;

	if (argc < 3)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] != '\0')
	{
		byte_count = ft_atoi(&argv[1][2]);
		file_idx = 2;
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		byte_count = ft_atoi(argv[2]);
		file_idx = 3;
	}
	else
		return (0);
	if (file_idx >= argc)
		ft_tail_stream(0, byte_count);
	else
	{
		while (file_idx < argc)
		{
			fd = open(argv[file_idx], O_RDONLY);
			if (fd < 0)
				ft_display_error(argv[0], argv[file_idx]);
			else
			{
				ft_tail_stream(fd, byte_count);
				close(fd);
			}
			file_idx++;
		}
	}
	return (0);
}
