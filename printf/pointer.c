/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:44:41 by iarslan           #+#    #+#             */
/*   Updated: 2024/12/07 18:04:43 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointerwrite(unsigned long long addr, char *base)
{
	char	x[16];
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (addr > 0)
	{
		x[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		count += ft_putchar(x[i]);
		i--;
	}
	return (count);
}

int	wrtp(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (unsigned long long)ptr;
	count += ft_putstr("0x");
	count += pointerwrite(addr, "0123456789abcdef");
	return (count);
}
