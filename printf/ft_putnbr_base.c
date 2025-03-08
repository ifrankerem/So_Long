/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:12:17 by iarslan           #+#    #+#             */
/*   Updated: 2024/12/07 18:04:26 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_putchar(char c)
{
	write(1, &c, 1);
}

static int	str_len(char *base)
{
	int	x;

	x = 0;
	while (base[x] != '\0')
		x++;
	return (x);
}

static void	convert_to_base(long lgnbr, char *base, char *result, int *m)
{
	int	base_len;

	base_len = str_len(base);
	if (lgnbr == 0)
	{
		result[(*m)++] = base[0];
		return ;
	}
	while (lgnbr > 0)
	{
		result[(*m)++] = base[lgnbr % base_len];
		lgnbr = lgnbr / base_len;
	}
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		m;
	char	result[32];
	long	lngbr;
	int		nbrlen;

	m = 0;
	lngbr = (long)nbr;
	if (lngbr < 0)
	{
		print_putchar('-');
		lngbr = -lngbr;
	}
	convert_to_base(lngbr, base, result, &m);
	nbrlen = m;
	while (m > 0)
		print_putchar(result[--m]);
	return (nbrlen);
}
