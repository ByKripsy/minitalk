/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:55:06 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/30 15:22:04 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

int	g_bit = 1;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bit = 1;
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(EXIT_SUCCESS);
	}
}

void	send_signal(char c, int j, int pid)
{
	int i;

	i = c >> (7 - j) & 1;
	if (i == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	parse_signal(char *str, int pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 4;
	str = ft_strjoin(str, &c);
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			g_bit = 0;
			send_signal(str[i], j, pid);
			j++;
			while (g_bit != 1)
				usleep(100);
		}
		i++;
	}
	free(str);
	exit(EXIT_SUCCESS);
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
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	str = argv[2];
	parse_signal(argv[2], ft_atoi(argv[1]));
	while (1)
		usleep(100);
	return (0);
}