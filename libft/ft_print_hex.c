/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:41:54 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/24 00:25:09 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

static void	ft_dec_to_hex(unsigned int nbr, char c)
{
	char	*lower;
	char	*upper;
	char	*base;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (c == 'x')
		base = lower;
	else
		base = upper;
	if (nbr < 16)
	{
		ft_print_char(base[nbr]);
	}
	else
	{
		ft_dec_to_hex((nbr / 16), c);
		ft_dec_to_hex((nbr % 16), c);
	}
}

int	ft_print_hex(unsigned int nbr, char c)
{
	if (!nbr)
		return (write(1, "0", 1));
	ft_dec_to_hex(nbr, c);
	return (ft_hexlen(nbr));
}
