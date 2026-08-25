/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyan <seyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:45:00 by seyan             #+#    #+#             */
/*   Updated: 2026/08/16 16:45:00 by seyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visi_row_left(char grid[8][8], int row)
{
	int	visi_count;
	int	max_height;
	int	col;

	col = 0;
	visi_count = 0;
	max_height = 0;
	while (col < 8)
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

int	visi_row_right(char grid[8][8], int row)
{
	int	visi_count;
	int	max_height;
	int	col;

	col = 7;
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

int	visi_col_top(char grid[8][8], int col)
{
	int	visi_count;
	int	max_height;
	int	row;

	row = 0;
	visi_count = 0;
	max_height = 0;
	while (row < 8)
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

int	visi_col_bottom(char grid[8][8], int col)
{
	int	visi_count;
	int	max_height;
	int	row;

	row = 7;
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
