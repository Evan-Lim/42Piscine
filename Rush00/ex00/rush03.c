/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 20:56:34 by linliu2           #+#    #+#             */
/*   Updated: 2026/08/09 18:23:45 by linliu2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	vertical_num(char q, char w, char e, int x)
{
	int	count_x;

	count_x = 1;
	ft_putchar(q);
	count_x++;
	while (count_x < x)
	{
		ft_putchar(w);
		count_x++;
	}
	if (count_x == x)
		ft_putchar(e);
}

void	horizon_num(int line_y, int x, int y)
{
	if (line_y == 1)
		vertical_num('A', 'B', 'C', x);
	else if (line_y < y)
		vertical_num('B', ' ', 'B', x);
	else
		vertical_num('A', 'B', 'C', x);
}

void	printerror(void)
{
	char	*msg;
	int		index;

	msg = "ERROR\n";
	index = 0;
	while (msg[index])
		ft_putchar(msg[index++]);
}

void	rush(int x, int y)
{
	int	line_y;

	line_y = 1;
	if (x > 0 && y > 0)
	{
		while (line_y <= y)
		{
			horizon_num(line_y, x, y);
			ft_putchar('\n');
			line_y++;
		}
	}
	else
		printerror();
}
