/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbhin-li <lbhin-li@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:16:15 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/08 16:15:56 by lbhin-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	vertical(char left, char middle, char right, int x_max)
{
	int	x_counter;

	x_counter = 1;
	ft_putchar(left);
	x_counter++;
	while (x_counter < x_max)
	{
		ft_putchar(middle);
		x_counter++;
	}
	if (x_counter == x_max)
		ft_putchar(right);
	ft_putchar('\n');
}

void	horizontal(int line_num, int x_max, int y_max)
{
	if (line_num == 1)
		vertical('A', 'B', 'C', x_max);
	else if (line_num == y_max)
		vertical('C', 'B', 'A', x_max);
	else
		vertical('B', ' ', 'B', x_max);
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
	int	line_num;

	line_num = 1;
	if ((x > 0) && (y > 0))
	{
		while (line_num <= y)
		{
			horizontal(line_num, x, y);
			line_num++;
		}
	}
	else
		printerror();
}
