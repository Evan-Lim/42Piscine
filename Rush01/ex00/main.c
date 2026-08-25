/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 09:53:04 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/15 15:28:07 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve_square(char grid[4][4], int row, int column, char *clues);
void	print_square(char grid[4][4]);
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
	if (countlen(str) != 31)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '1' || str[i] > '4'))
			return (0);
		if ((i % 2 == 0) && !(str[i] >= '1' && str[i] <= '4'))
			return (0);
		if ((i % 2 != 0) && (str[i] != ' '))
			return (0);
		if (str[i] >= '1' && str[i] <= '4')
			num_count++;
		i++;
	}
	if (num_count == 16)
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
		if (str[i] >= '1' && str[i] <= '4')
		{
			clues[j] = str[i];
			j++;
		}
		i++;
	}
	clues[j] = '\0';
}

void	initialise_grid(char grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
}

// testing
// #include <stdio.h>
// end of testing

int	main(int argc, char **argv)
{
	char	grid[4][4];
	char	clues[17];
	int		k;

	k = 0;
	initialise_grid(grid);
	while (k < 16)
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

/*
// test
int		i_test;
int		j_test;

i_test = 0;
j_test = 0;
printf("%s\n", argv[1]);
printf("%d\n", is_valid(argv));
printf("%s\n", clues);
while (i_test < 4)
{
	j_test = 0;
	while (j_test < 4)
	{
		printf("%d", grid[i_test][j_test]);
		j_test++;
	}
	printf("\n");
	i_test++;
}
// end of test
*/
