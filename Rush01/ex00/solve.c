/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:05:09 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/15 15:30:54 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// FUNCTION PROTOTYPES
int		visi_row_left(char grid[4][4], int row);
int		visi_row_right(char grid[4][4], int row);
int		visi_col_top(char grid[4][4], int col);
int		visi_col_bottom(char grid[4][4], int col);

// CHECK FOR DUPLICATES AMONG THE ROWS AND COLUMNS
int	valid_placement(char grid[4][4], int row, int column, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (grid[i][column] == value)
			return (0);
		i++;
	}
	while (j < 4)
	{
		if (grid[row][j] == value)
			return (0);
		j++;
	}
	return (1);
}

int	check_clues(char grid[4][4], char *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (visi_col_top(grid, i) != clues[i] - '0')
			return (0);
		if (visi_col_bottom(grid, i) != clues[i + 4] - '0')
			return (0);
		if (visi_row_left(grid, i) != clues[i + 8] - '0')
			return (0);
		if (visi_row_right(grid, i) != clues[i + 12] - '0')
			return (0);
		i++;
	}
	return (1);
}

int	solve_square(char grid[4][4], int row, int column, char *clues)
{
	int	num;

	num = 1;
	if (row == 4)
	{
		if (check_clues(grid, clues))
			return (1);
		else
			return (0);
	}
	if (column == 4)
		return (solve_square(grid, row + 1, 0, clues));
	while (num <= 4)
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

void	print_square(char grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	c = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
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
