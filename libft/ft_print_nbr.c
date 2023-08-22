/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:39:47 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/26 11:26:29 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int	nbr_len;

	if (!nbr)
		return (write(1, "0", 1));
	nbr_len = 0;
	if (nbr == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nbr < 0)
	{
		nbr_len += write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		nbr_len += ft_print_nbr(nbr / 10);
	if (nbr >= 0)
		nbr_len += ft_print_char((nbr % 10) + '0');
	return (nbr_len);
}
