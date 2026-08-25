/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyan <seyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:30:00 by seyan             #+#    #+#             */
/*   Updated: 2026/08/16 16:30:00 by seyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve_square(char grid[8][8], int row, int column, char *clues);
void	print_square(char grid[8][8]);
void	print_error(void);

int	countlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid(char *str)
{
	int	i;
	int	num_count;

	i = 0;
	num_count = 0;
	if (countlen(str) != 63)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '1' || str[i] > '8'))
			return (0);
		if ((i % 2 == 0) && !(str[i] >= '1' && str[i] <= '8'))
			return (0);
		if ((i % 2 != 0) && (str[i] != ' '))
			return (0);
		if (str[i] >= '1' && str[i] <= '8')
			num_count++;
		i++;
	}
	if (num_count == 32)
		return (1);
	return (0);
}

void	get_clues(char *str, char *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '8')
		{
			clues[j] = str[i];
			j++;
		}
		i++;
	}
	clues[j] = '\0';
}

void	initialise_grid(char grid[8][8])
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	grid[8][8];
	char	clues[33];
	int		k;

	k = 0;
	initialise_grid(grid);
	while (k < 32)
		clues[k++] = 0;
	clues[k] = '\0';
	if (argc == 2)
	{
		if (is_valid(argv[1]))
		{
			get_clues(argv[1], clues);
			if (solve_square(grid, 0, 0, clues))
				print_square(grid);
			else
				print_error();
		}
		else
			print_error();
	}
	else
		print_error();
	return (0);
}
