/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:37:12 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 16:55:13 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	uc[2];

	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (s1[i] == s2[i]))
		i++;
	uc[0] = (unsigned char)s1[i];
	uc[1] = (unsigned char)s2[i];
	return (uc[0] - uc[1]);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int		x;

	s1 = "A";
	s2 = "ABC";
	x = ft_strcmp(s1, s2);
	printf("%d", x);
}
*/
