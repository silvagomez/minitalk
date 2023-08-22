/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:41:12 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/21 15:42:17 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int unbr)
{
	int	unbr_len;

	if (!unbr)
		return (write(1, "0", 1));
	unbr_len = 0;
	if (unbr >= 10)
		unbr_len += ft_print_unbr(unbr / 10);
	//if (unbr >= 0)
	else
		unbr_len += ft_print_char((unbr % 10) + '0');
	return (unbr_len);
}
