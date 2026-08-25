/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 07:50:49 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 07:23:30 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	print_hex(unsigned int val, int pad)
{
	char	*hex;
	char	buf[16];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < pad)
		buf[i++] = '0';
	i = pad - 1;
	while (val > 0 && i >= 0)
	{
		buf[i--] = hex[val % 16];
		val /= 16;
	}
	write(1, buf, pad);
}

void	print_ascii(unsigned char *buf, int size)
{
	int	i;

	write(1, " |", 2);
	i = 0;
	while (i < size)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	print_line(unsigned char *buf, int size, int total_bytes)
{
	int	i;

	print_hex(total_bytes, 8);
	write(1, "  ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex(buf[i], 2);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	print_ascii(buf, size);
}

void	ft_hexdump(int fd)
{
	unsigned char	buf[16];
	int				bytes_read;
	int				total_bytes;

	total_bytes = 0;
	bytes_read = read(fd, buf, 16);
	while (bytes_read > 0)
	{
		print_line(buf, bytes_read, total_bytes);
		total_bytes += bytes_read;
		bytes_read = read(fd, buf, 16);
	}
	if (total_bytes > 0)
	{
		print_hex(total_bytes, 8);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc < 2 || strcmp(argv[1], "-C") != 0)
		return (0);
	if (argc == 2)
		ft_hexdump(0);
	else
	{
		i = 2;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd >= 0)
			{
				ft_hexdump(fd);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
