/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:59:28 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 17:06:44 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	uc[2];

	i = 0;
	if (n == 0)
		return (0);
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (s1[i] == s2[i]) && (i < (n
				- 1)))
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

	s1 = "ABCD";
	s2 = "ABC";
	x = ft_strncmp(s1, s2, 3);
	printf("%d", x);
}
*/
