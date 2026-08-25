/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyan <seyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:15:00 by seyan             #+#    #+#             */
/*   Updated: 2026/08/16 17:15:00 by seyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_square(char grid[8][8])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 8)
	{
		col = 0;
		while (col < 8)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 7)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	print_error(void)
{
	int		i;
	char	*str;

	i = 0;
	str = "Error";
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}
