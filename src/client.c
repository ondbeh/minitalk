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

static void	send_char(int pid, char character)
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
		usleep(50);
	}
}

static void	send_message(int pid, char *message)
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

int	main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
	{
		printf("Unexpected amount of arguments!");
		return (1);
	}
	server_pid = atoi(argv[1]);
	printf ("Sending message to server pid:%d\n", server_pid);
	send_message(server_pid, argv[2]);
	return (0);
}
