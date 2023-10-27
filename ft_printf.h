/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:07:11 by clegros           #+#    #+#             */
/*   Updated: 2023/10/27 13:23:12 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list ap, char format);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putdigit(long n, int base, int x);
int	ft_putptr(void *ptr);
int	ft_putadd(uintptr_t n, const char format);
int	ft_putuns(unsigned int n);

#endif
