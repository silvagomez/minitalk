/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:58 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/06/24 00:21:03 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_print_ptr(void *address);
int	ft_print_unbr(unsigned int unbr);
int	ft_print_hex(unsigned int nbr, char c);

#endif
