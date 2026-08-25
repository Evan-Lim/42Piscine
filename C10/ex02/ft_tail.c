/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 07:38:24 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/25 07:25:52 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail_stream(int fd, int byte_count)
{
	char	*buf;
	char	ch;
	int		total_bytes;

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
	print_tail(buf, total_bytes, byte_count);
	free(buf);
}

int	parse_byte_count(char **argv, int *file_idx)
{
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] != '\0')
	{
		*file_idx = 2;
		return (ft_atoi(&argv[1][2]));
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		*file_idx = 3;
		return (ft_atoi(argv[2]));
	}
	return (-1);
}

void	process_files(int argc, char **argv, int file_idx, int byte_count)
{
	int	fd;

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
}

int	main(int argc, char **argv)
{
	int	byte_count;
	int	file_idx;

	if (argc < 3)
		return (0);
	byte_count = parse_byte_count(argv, &file_idx);
	if (byte_count == -1)
		return (0);
	process_files(argc, argv, file_idx, byte_count);
	return (0);
}
