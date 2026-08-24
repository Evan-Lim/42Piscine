/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 08:08:49 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/12 11:02:30 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while ((to_find[j] != '\0') && (str[i + j] == to_find[j]))
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <unistd.h>

int	main(void)
{
	char	*str;
	char	*to_find;
	char	*result;
	int		i;

	i = 0;
	str = "ABCDEFGHIJK";
	to_find = "FGH";
	result = ft_strstr(str, to_find);
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
}
*/
