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

static void	terminate_client(int status, char *message)
{
	ft_putchar_fd('\n', 2);
	if (message)
		ft_putendl_fd(message, 2);
	ft_putendl_fd("Client has been terminated", 2);
	exit(status);
}

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

static void	signal_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_putendl_fd("Message has been successfully sent", 1);
}

int	main(const int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
		terminate_client(1, "Invalid number of arguments");
	server_pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR
		|| signal(SIGUSR2, signal_handler) == SIG_ERR)
		terminate_client(1, "Error while setting signal handler");
	send_message(server_pid, argv[2]);
	return (0);
}
