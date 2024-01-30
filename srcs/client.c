/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:06 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/30 13:09:10 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

int g_bit = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bit = 0;
		ft_printf("Message received\n");
	}
	exit(EXIT_SUCCESS);
}

void text_to_signal(char *str, int pid)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			g_bit = 1;
			k = str[i] >> (7 - j) & 1;
			if (k == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
			// while (g_bit)
		}
		// if (j == 8)
		// {
		// 	usleep(600);
		// 	g_bit = 0;
		// }
		i++;
	}
}

int main(int argc, char **argv)
{
	char *str;
	struct sigaction action;

	action.sa_handler = sig_handler;
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (0);
	}
	sigaction(SIGUSR1, &action, NULL);
	str = argv[2];
	text_to_signal(argv[2], ft_atoi(argv[1]));
	while (1)
		usleep(100);
	return (0);
}