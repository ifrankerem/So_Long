/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:05:49 by iarslan           #+#    #+#             */
/*   Updated: 2024/12/07 18:04:03 by iarslan          ###   ########.fr       */
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

static void	convert_to_base(unsigned int lgnbr,
char *base, char *result, int *m)
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

int	ft_putnbr_basever2(unsigned int nbr, char *base)
{
	int		m;
	char	result[32];
	int		nbrlen;

	m = 0;
	convert_to_base(nbr, base, result, &m);
	nbrlen = m;
	while (m > 0)
		print_putchar(result[--m]);
	return (nbrlen);
}
