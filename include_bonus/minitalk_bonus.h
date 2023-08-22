/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:28:00 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/23 00:01:29 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// Allowed libraries
# include "../libft/libft.h"

# define ERR_ARGS	"ERROR : Incorrect number of arguments"
# define ERR_PID	"ERROR : Incorrect ID process format"
# define ERR_PIDZ	"ERROR : ID process can not be zero"
# define ERR_EMPTY	"ERROR : Empty message"

void	error_handling(char *s);
int		check_argv(char *s1, char *s2);
#endif
