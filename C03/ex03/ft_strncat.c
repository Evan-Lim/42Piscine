/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:31:49 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 17:41:54 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while ((src[j] != '\0') && (j < nb))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
#include <unistd.h>

int	main(void)
{
	char	*src;
	char	dest[7];
	int		i;

	i = 0;
	dest[0] = 'A';
	dest[1] = 'B';
	dest[2] = 'C';
	dest[3] = '\0';
	dest[4] = '\0';
	dest[5] = '\0';
	dest[6] = '\0';
	src = "DEF";
	ft_strncat(dest, src, 2);
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}
}
*/
