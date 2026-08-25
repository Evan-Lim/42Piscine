/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyan <seyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:10:00 by seyan             #+#    #+#             */
/*   Updated: 2026/08/16 17:15:00 by seyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visi_row_left(char grid[8][8], int row);
int	visi_row_right(char grid[8][8], int row);
int	visi_col_top(char grid[8][8], int col);
int	visi_col_bottom(char grid[8][8], int col);

int	valid_placement(char grid[8][8], int row, int column, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		if (grid[i][column] == value)
			return (0);
		i++;
	}
	while (j < 8)
	{
		if (grid[row][j] == value)
			return (0);
		j++;
	}
	return (1);
}

int	check_partial(char grid[8][8], int row, int col, char *clues)
{
	int	left;
	int	top;

	left = visi_row_left(grid, row);
	top = visi_col_top(grid, col);
	if (left > clues[row + 16] - '0')
		return (0);
	if (left + (7 - col) < clues[row + 16] - '0')
		return (0);
	if (top > clues[col] - '0')
		return (0);
	if (top + (7 - row) < clues[col] - '0')
		return (0);
	return (1);
}

int	check_finished(char grid[8][8], int row, int col, char *clues)
{
	if (col == 7)
	{
		if (visi_row_left(grid, row) != clues[row + 16] - '0')
			return (0);
		if (visi_row_right(grid, row) != clues[row + 24] - '0')
			return (0);
	}
	if (row == 7)
	{
		if (visi_col_top(grid, col) != clues[col] - '0')
			return (0);
		if (visi_col_bottom(grid, col) != clues[col + 8] - '0')
			return (0);
	}
	return (1);
}

int	check_position(char grid[8][8], int row, int col, char *clues)
{
	if (!check_partial(grid, row, col, clues))
		return (0);
	if (!check_finished(grid, row, col, clues))
		return (0);
	return (1);
}

int	solve_square(char grid[8][8], int row, int column, char *clues)
{
	int	num;

	num = 1;
	if (row == 8)
		return (1);
	if (column == 8)
		return (solve_square(grid, row + 1, 0, clues));
	while (num <= 8)
	{
		if (valid_placement(grid, row, column, num))
		{
			grid[row][column] = num;
			if (check_position(grid, row, column, clues)
				&& solve_square(grid, row, column + 1, clues))
				return (1);
			grid[row][column] = 0;
		}
		num++;
	}
	return (0);
}
