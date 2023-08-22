/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:40:26 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/23 22:49:09 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long nbr)
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

static void	ft_dec_to_hex(unsigned long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		ft_print_char(base[nbr]);
	}
	else
	{
		ft_dec_to_hex(nbr / 16);
		ft_dec_to_hex(nbr % 16);
	}
}

int	ft_print_ptr(void *address)
{
	unsigned long	nbr;
	int				total;

	if (!address)
		return (write(1, "0x0", 3));
	total = 0;
	total += ft_print_str("0x");
	nbr = (unsigned long)address;
	ft_dec_to_hex(nbr);
	total += ft_hexlen(nbr);
	return (total);
}
