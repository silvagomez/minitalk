/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:26:05 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/08/23 12:53:16 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
 * Since a char is 8 bits in most systems, the loop runs 8 times.
 * 8 bits = 1 byte;
 *
 * Bitwise OR assignment operator (|=).
 *		octet |= 1; // octet = octet | 1 
 *
 * If the comparison evaluates to 1, it sets the corresponding bit 
 * in octet to 1, and if the comparison evaluates to 0, 
 * it leaves the corresponding bit unchanged.
 *
 * octet = octet << 1 // bitwise left shift
 */
static void	server_act(int sig, siginfo_t *info, void *context)
{
	static unsigned char	octet;
	static int				bit;

	(void) context;
	if (sig == SIGUSR1)
		octet |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", octet);
		if (octet == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		octet = 0;
	}
	else
		octet <<= 1;
}

/*
 * SIGUSR1 and SIGUSR2 Usage:
 * The server process receives these signals from the client process.
 * When the client sends a SIGUSR1 signal, it's interpreted as a bit value of 1.
 * When the client sends a SIGUSR2 signal, it's interpreted as a bit value of 0.
 */
int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sact;

	server_pid = getpid();
	ft_printf("SERVER PID: %d\n", server_pid);
	sigemptyset(&sact.sa_mask);
	sact.sa_sigaction = server_act;
	sact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	while (1)
		pause();
	return (0);
}
