/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 09:29:32 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 08:26:58 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>

*/

int	is_alphanumeric(int i, char *str)
{
	if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a')
			&& (str[i] <= 'z')) || ((str[i] >= '0') && (str[i] <= '9')))
		return (1);
	else
		return (0);
}

int	is_start(int i, char *str)
{
	if (i != 0)
	{
		if ((is_alphanumeric(i, str) == 1) && (is_alphanumeric((i - 1),
					str) != 1))
			return (1);
		else
			return (0);
	}
	else
	{
		if (is_alphanumeric(i, str) == 1)
			return (1);
		else
			return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_start(i, str) == 1)
		{
			if ((str[i] >= 'a') && (str[i] <= 'z'))
				str[i] = str[i] - 32;
		}
		if ((is_start(i, str) != 1) && (is_alphanumeric(i, str) == 1))
		{
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str[] = "hi, how arE yOU? 42words foRty-two; fifty+and+one";
	int		i;

	i = 0;
	ft_strcapitalize(str);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
*/
