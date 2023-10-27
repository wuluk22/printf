/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:51:15 by clegros           #+#    #+#             */
/*   Updated: 2023/10/27 13:37:31 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	size_t	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putadd((uintptr_t)ptr, 'x');
	return (len);
}

int	ft_putadd(uintptr_t n, const char format)
{
	size_t	len;
	char	ref;

	len = 0;
	ref = 'a';
	if (format == 'X')
		ref = 'A';
	if (n >= 16)
		len += ft_putadd(n / 16, format);
	n %= 16;
	if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar(n - 10 + ref);
	return (len + 1);
}

int	ft_putuns(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putuns(n / 10);
	len += ft_putchar('0' + (n % 10));
	return (len);
}
