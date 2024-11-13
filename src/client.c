/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:50:34 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/28 18:10:38 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	send_char(const int pid, const char character)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if ((character >> (7 - i)) & 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		++i;
		pause();
		usleep(50);
	}
}

static void	send_message(const int pid, const char *message)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		++i;
	}
	send_char(pid, message[i]);
}

void	signal_handler(int signum)
{
	(void)signum;
}

int	main(const int argc, char **argv)
{
	int		server_pid;

	signal(SIGUSR1, signal_handler);
	if (argc != 3)
	{
		ft_putstr_fd("Unexpected amount of arguments!", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}
