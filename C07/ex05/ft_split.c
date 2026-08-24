/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:07:29 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/17 09:34:28 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (str[i])
	{
		if (!is_delimiter(str[i], charset))
		{
			if (is_word == 0)
			{
				count++;
				is_word = 1;
			}
		}
		else
			is_word = 0;
		i++;
	}
	return (count);
}

int	get_word_len(char *str, char *charset)
{
	int	length;

	length = 0;
	while (str[length] && !is_delimiter(str[length], charset))
		length++;
	return (length);
}

char	*word_dup(char *str, char *charset)
{
	int		len;
	char	*word;
	int		i;

	len = get_word_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		k;

	i = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!arr)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_delimiter(str[i], charset))
			i++;
		if (str[i])
		{
			arr[k] = word_dup(&str[i], charset);
			k++;
			i += get_word_len(&str[i], charset);
		}
	}
	arr[k] = NULL;
	return (arr);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**result;
	int		i;

	if (argc == 3)
	{
		result = ft_split(argv[1], argv[2]);
		if (!result)
			return (1);
		i = 0;
		while (result[i] != NULL)
		{
			printf("result[%d]: %s\n", i, result[i]);
			i++;
		}
		printf("result[%d]: %s\n", i, result[i]);
		i = 0;
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
	return (0);
}
*/
