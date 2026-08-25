/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyan <seyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:40:00 by seyan             #+#    #+#             */
/*   Updated: 2026/08/16 16:40:00 by seyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	visi_row_left(char grid[5][5], int row);
int	visi_row_right(char grid[5][5], int row);
int	visi_col_top(char grid[5][5], int col);
int	visi_col_bottom(char grid[5][5], int col);

int	valid_placement(char grid[5][5], int row, int column, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		if (grid[i][column] == value)
			return (0);
		i++;
	}
	while (j < 5)
	{
		if (grid[row][j] == value)
			return (0);
		j++;
	}
	return (1);
}

int	check_clues(char grid[5][5], char *clues)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (visi_col_top(grid, i) != clues[i] - '0')
			return (0);
		if (visi_col_bottom(grid, i) != clues[i + 5] - '0')
			return (0);
		if (visi_row_left(grid, i) != clues[i + 10] - '0')
			return (0);
		if (visi_row_right(grid, i) != clues[i + 15] - '0')
			return (0);
		i++;
	}
	return (1);
}

int	solve_square(char grid[5][5], int row, int column, char *clues)
{
	int	num;

	num = 1;
	if (row == 5)
	{
		if (check_clues(grid, clues))
			return (1);
		return (0);
	}
	if (column == 5)
		return (solve_square(grid, row + 1, 0, clues));
	while (num <= 5)
	{
		if (valid_placement(grid, row, column, num))
		{
			grid[row][column] = num;
			if (solve_square(grid, row, column + 1, clues))
				return (1);
			grid[row][column] = 0;
		}
		num++;
	}
	return (0);
}

void	print_square(char grid[5][5])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 5)
	{
		col = 0;
		while (col < 5)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 4)
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
