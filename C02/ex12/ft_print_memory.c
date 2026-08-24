/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim-hon <elim-hon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:29:11 by elim-hon          #+#    #+#             */
/*   Updated: 2026/08/11 10:14:37 by elim-hon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printhex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	printaddr(unsigned long long addr)
{
	char	buf[16];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buf[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	write(1, buf, 16);
	write(1, ": ", 2);
}

void	printhexcontent(unsigned char *ptr, int l)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < l)
			printhex(ptr[i]);
		else
		{
			write(1, " ", 1);
			write(1, " ", 1);
		}
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
}

void	printasciicontent(unsigned char *ptr, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	l;

	if (size == 0)
		return (addr);
	ptr = (unsigned char *)addr;
	while (size > 0)
	{
		if (size < 16)
			l = size;
		else
			l = 16;
		printaddr((unsigned long long)ptr);
		printhexcontent(ptr, l);
		printasciicontent(ptr, l);
		write(1, "\n", 1);
		ptr = ptr + l;
		size = size - l;
	}
	return (addr);
}

/*
int	main(void)
{
	char	str[] = "Bonjour les aminches\t\n\tc\t est fou\ttout\tce
	qu on peut faire avec\t\t\tprint_memory\n\n\n\tlol\nlol\n \t";
	ft_print_memory(str, 92);
	write(1, "\n", 1);
	ft_print_memory(str, 20);
	return (0);
}
*/

// Place the string on 1 line before testing it
// For Norminette compliance
