/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:38:30 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/23 16:08:12 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	unsigned int	idx;

	if (!str)
		return (write(1, "(null)", 6));
	idx = 0;
	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}
	return (idx);
}
