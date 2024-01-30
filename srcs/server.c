/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:21:17 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/30 15:01:13 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"


void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int power;
	static char byte;

	(void)context;
	if (sig == SIGUSR1)
		byte += 1 << (7 - power);
	if (sig == SIGUSR2)
		byte += 0 << (7 - power);
	power++;
	kill(siginfo->si_pid, SIGUSR1);
	if (power == 8 && byte)
	{
		ft_putchar(byte);
		if (byte == 4)
		{
			ft_putchar('\n');
			kill(siginfo->si_pid, SIGUSR2);
		}
		power = 0;
		byte = 0;
 	}
}

int main(int argc, char **argv)
{
	struct sigaction action;

	(void)argc;
	(void)argv;
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &action, NULL) < 0 
		|| sigaction(SIGUSR2, &action, NULL) < 0)
	{
		ft_printf("Error can't handle signal\n");
		return (0);
	}
	while (100)
		pause();
	return (0);
}