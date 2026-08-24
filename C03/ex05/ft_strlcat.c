/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 08:52:13 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/12 09:34:04 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	src_len = 0;
	dest_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	while ((dest[dest_len] != '\0') && (dest_len < size))
		dest_len++;
	if (size <= dest_len)
		return (size + src_len);
	while ((src[i] != '\0') && ((dest_len + i) < (size - 1)))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <unistd.h>

int	main(void)
{
	char			*src;
	char			dest[9];
	unsigned int	ans;
	int				i;
	char			ansc;

	i = 0;
	dest[0] = 'A';
	dest[1] = 'B';
	dest[2] = 'C';
	dest[3] = '\0';
	dest[4] = '\0';
	dest[5] = '\0';
	dest[6] = '\0';
	dest[7] = '\0';
	dest[8] = '\0';
	src = "DEFGHI";
	ans = ft_strlcat(dest, src, 6);
	ansc = ans + '0';
	write(1, &ansc, 1);
	write(1, "\n", 1);
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}
}
*/
