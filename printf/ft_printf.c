/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:44:29 by iarslan           #+#    #+#             */
/*   Updated: 2024/12/07 21:07:37 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formatprint(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar((char)va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		count += wrtp(va_arg(ap, void *));
	else if (*format == 'i' || *format == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		count += ft_putnbr_basever2((unsigned int)va_arg(ap, unsigned int),
				"0123456789");
	else if (*format == 'x')
		count += ft_putnbr_basever2((unsigned int)va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (*format == 'X')
		count += ft_putnbr_basever2((unsigned int)va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	else if (*format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += ft_formatprint(format + 1, ap);
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
