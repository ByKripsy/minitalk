/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:21:17 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/30 13:10:54 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"


void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int power;
	static char byte;

	(void)siginfo;
	(void)context;
	if (sig == SIGUSR1)
		byte += 1 << (7 - power);
	if (sig == SIGUSR2)
		byte += 0 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
		kill(siginfo->si_pid, SIGUSR1);
		ft_printf("pid: %d\n", siginfo->si_pid);
		usleep(100);
 	}
}

int main(int argc, char **argv)
{
	struct sigaction action;

	(void)argc;
	(void)argv;
	action.sa_sigaction = sig_handler;
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