/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:08:04 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/16 14:33:57 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	concatenate(int size, char **strs, char *sep, char *string)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			string[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				string[k++] = sep[j++];
		}
		i++;
	}
	string[k] = '\0';
}

int	total_length(int size, char **strs)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*string;

	if (size <= 0)
	{
		string = (char *)malloc(sizeof(char) * 1);
		if (string == NULL)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	length = total_length(size, strs);
	if (size > 1)
		length = length + (ft_strlen(sep) * (size - 1));
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	concatenate(size, strs, sep, string);
	return (string);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*string;
	char	*strs[] = {"Hello", "world", "this", "is", "a", "string."};

	string = ft_strjoin(6, strs, ", ---");
	printf("%s\n", string);
	free(string);
	return (0);
}
*/
