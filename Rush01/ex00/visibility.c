/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jialim <jialim@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:13:48 by jialim            #+#    #+#             */
/*   Updated: 2026/08/15 15:27:16 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visi_row_left(char grid[4][4], int row)
{
	int	visi_count;
	int	max_height;
	int	col;

	col = 0;
	visi_count = 0;
	max_height = 0;
	while (col < 4)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visi_count++;
		}
		col++;
	}
	return (visi_count);
}

int	visi_row_right(char grid[4][4], int row)
{
	int	visi_count;
	int	max_height;
	int	col;

	col = 3;
	visi_count = 0;
	max_height = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visi_count++;
		}
		col--;
	}
	return (visi_count);
}

int	visi_col_top(char grid[4][4], int col)
{
	int	visi_count;
	int	max_height;
	int	row;

	row = 0;
	visi_count = 0;
	max_height = 0;
	while (row < 4)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visi_count++;
		}
		row++;
	}
	return (visi_count);
}

int	visi_col_bottom(char grid[4][4], int col)
{
	int	visi_count;
	int	max_height;
	int	row;

	row = 3;
	visi_count = 0;
	max_height = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visi_count++;
		}
		row--;
	}
	return (visi_count);
}
