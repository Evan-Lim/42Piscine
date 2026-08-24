/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 08:34:02 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/16 09:56:21 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_board(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_safe(int board[10], int r, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (board[i] == r || abs(board[i] - r) == (c - i))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int col, int *count)
{
	int	r;

	if (col == 10)
	{
		write_board(board);
		write(1, "\n", 1);
		*count += 1;
		return ;
	}
	r = 0;
	while (r < 10)
	{
		if (is_safe(board, r, col))
		{
			board[col] = r;
			solve(board, col + 1, count);
		}
		r++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}
/*
int	main(void)
{
	ft_ten_queens_puzzle();
}
*/
