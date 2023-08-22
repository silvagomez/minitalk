/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:26:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/23 00:55:03 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	ft_printf("Message size was: %d\n", idx);
}

void	feedback_server(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("SERVER : Message received\n");
}

/*
 * Same behaivor with signal();
 * signal(SIGUSR2, feedback_server);
 */
int	main(int ac, char *av[])
{
	pid_t				server_pid;
	struct sigaction	sact;

	if (ac != 3)
		error_handling(ERR_ARGS);
	server_pid = check_argv(av[1], av[2]);
	sigemptyset(&sact.sa_mask);
	sact.sa_handler = feedback_server;
	sigaction(SIGUSR2, &sact, NULL);
	send_message(av[2], server_pid);
	return (0);
}
