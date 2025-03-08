/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:28:37 by iarslan           #+#    #+#             */
/*   Updated: 2024/12/07 21:28:37 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nb)
{
	long	lnb;
	int		i;

	i = 0;
	lnb = (long)nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
		i++;
	}
	if (lnb > 9)
	{
		i += ft_putnbr(lnb / 10);
	}
	print_putchar(lnb % 10 + '0');
	i++;
	return (i);
}
