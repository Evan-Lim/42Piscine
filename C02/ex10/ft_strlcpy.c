/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 10:03:28 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 08:39:39 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>

*/

int	countstr(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (countstr(src));
	}
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (countstr(src));
}

/*
int	main(void)
{
	char			*src;
	char			dest[11];
	unsigned int	i;
	char			i_char;
	int				count;

	src = "Hellowor";
	i = ft_strlcpy(dest, src, 5);
	i_char = i + '0';
	write(1, &i_char, 1);
	write(1, "\n", 1);
	count = 0;
	while (dest[count] != '\0')
	{
		write(1, &dest[count], 1);
		count++;
	}
}
*/
