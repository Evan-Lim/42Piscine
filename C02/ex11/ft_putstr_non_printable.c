/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:28:26 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 12:42:45 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	convert_char(char a)
{
	if (a == 10)
		return ('a');
	else if (a == 11)
		return ('b');
	else if (a == 12)
		return ('c');
	else if (a == 13)
		return ('d');
	else if (a == 14)
		return ('e');
	else if (a == 15)
		return ('f');
	else
		return (a + '0');
}

void	case_nonprintable(char strchar)
{
	int				arrnum[2];
	int				div;
	int				mod;
	char			arrchar[2];
	unsigned char	strchar_u;

	strchar_u = (unsigned char)strchar;
	div = strchar_u / 16;
	mod = strchar_u % 16;
	arrnum[0] = 0;
	arrnum[1] = mod;
	if (div != 0)
	{
		mod = div % 16;
		arrnum[0] = mod;
	}
	arrchar[0] = convert_char(arrnum[0]);
	arrchar[1] = convert_char(arrnum[1]);
	write(1, "\\", 1);
	write(1, arrchar, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32) && (str[i] <= 126))
			write(1, &str[i], 1);
		else
		{
			case_nonprintable(str[i]);
		}
		i++;
	}
}

/*
int	main(void)
{
	char	*str;

	str = "Hello\nHow are you?\t";
	ft_putstr_non_printable(str);
}
*/
