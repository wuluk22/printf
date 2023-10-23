/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:48:50 by clegros           #+#    #+#             */
/*   Updated: 2023/10/17 14:13:59 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		ft_putchar((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	ft_putdigit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putdigit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (ft_putchar(symbols[n]));
	}
	else
	{
		count = ft_putdigit(n / base, base);
		return (count + ft_putdigit(n % base, base));
	}
}

int	ft_format(va_list ap, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
//	else if (format == 'p')
//		len += ft_
	else if (format == 'd' || format == 'i')
		len += ft_putdigit((long)(va_arg(ap, int)), 10);
	else if (format == 'u')
		len += (unsigned)(ft_putdigit((long)(va_arg(ap, int)), 10));
	else if (format == 'x' || format == 'X')
		len += ft_putdigit((long)(va_arg(ap, unsigned int)), 16);
//	else if (format == '%')
//		len += ft_
	return (len);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	len;

	va_start(args, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			len += ft_format(args, *(++str));
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	int	count;

	count = ft_printf("%d\n", 2);
	ft_printf("chars written : %d\n", count);
	count = printf("%d\n", 2);
	printf("chars written : %d\n", count);
}