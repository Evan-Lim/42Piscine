/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:33:13 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/09 14:45:45 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>

*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	*src;
	char	dest[11];
	int		i;

	src = "Helloworld";
	ft_strcpy(dest, src);
	i = 0;
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}
}
*/
