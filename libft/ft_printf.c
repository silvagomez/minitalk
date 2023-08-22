/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:41:45 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/26 13:23:37 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	ft_case(char c, va_list lst_args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(lst_args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(lst_args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(lst_args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(lst_args, int)));
	else if (c == 'u')
		return (ft_print_unbr(va_arg(lst_args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(lst_args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_print_hex(va_arg(lst_args, unsigned int), 'X'));
	else if (c == '%')
		return (ft_print_char(c));
	else
		return (ft_print_char(c));
	return (-1);
}

// After ft_case() idx++ is necesary, in order to avoid printing char after %
int	ft_printf(const char *str, ...)
{
	va_list	lst_args;
	int		idx;
	int		total;
	size_t	len;

	idx = 0;
	total = 0;
	len = ft_strlen(str);
	if (len == 1 && str[idx] == '%')
		return (total);
	va_start(lst_args, str);
	while (str[idx] != '\0')
	{
		if (str[idx] == '%' && str[idx + 1])
		{
			total += ft_case(str[idx + 1], lst_args);
			idx++;
		}
		else
			total += ft_print_char(str[idx]);
		idx++;
	}
	va_end(lst_args);
	return (total);
}
