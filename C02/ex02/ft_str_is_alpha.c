/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:05:39 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/09 16:47:23 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int	return_value(int other)
{
	if (other != 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	other;

	i = 0;
	other = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a')
				&& (str[i] <= 'z')))
		{
			i++;
		}
		else
		{
			other++;
			i++;
		}
	}
	return (return_value(other));
}

/*
int	main(void)
{
	char	*str;
	int	x;
	str = "";
	x = ft_str_is_alpha(str);
	printf("%d", x);
}
*/
