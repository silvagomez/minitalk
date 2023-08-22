/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:49:19 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/22 23:50:20 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

/*
 * Since a chat is 8 bits in most systems, the loop runs 8 times.
 * 8 bits = 1 byte.
 *
 * (octect & 1) bitwise logical operation AND.
 * Other way to achieve similar behavior is (octet % 2 == 1)
 */
static void	send_char(unsigned char c, pid_t server_pid)
{
	int				bit;
	unsigned char	octet;

	octet = c;
	bit = 8;
	while (bit-- > 0)
	{
		octet = c >> bit;
		if (octet & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
}

static void	send_message(char *s, pid_t server_pid)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		send_char(s[idx], server_pid);
		idx++;
	}
	send_char(s[idx], server_pid);
	ft_printf("Message size: %d\n", idx);
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;

	if (ac != 3)
		error_handling(ERR_ARGS);
	server_pid = check_argv(av[1], av[2]);
	send_message(av[2], server_pid);
	return (0);
}
