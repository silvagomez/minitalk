/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:58:39 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/23 00:23:06 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error_handling(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

int	check_argv(char *s1, char *s2)
{
	int	idx;
	int	pid;

	idx = 0;
	while (s1[idx])
	{
		if (!ft_isdigit(s1[idx]))
			error_handling(ERR_PID);
		idx++;
	}
	pid = ft_atoi(s1);
	if (pid < 1)
		error_handling(ERR_PIDZ);
	if (!s2 || !*s2)
		error_handling(ERR_EMPTY);
	return (pid);
}
