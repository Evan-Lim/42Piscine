/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 09:20:29 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/10 09:22:28 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
*/

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str[] = "Hello World! Nice to meet you!";
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
*/
