/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:10:26 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/10 08:32:17 by elim-hon         ###   ########.fr       */
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

int	ft_str_is_numeric(char *str)
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
		if ((str[i] >= '0') && (str[i] <= '9'))
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
	int		x;

	str = "";
	x = ft_str_is_numeric(str);
	printf("%d", x);
}
*/
