/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:50:34 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/28 18:35:56 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	terminate_server(int status, char *message)
{
	int		fd;

	if (status == 0)
		fd = 1;
	else
		fd = 2;
	ft_putchar_fd('\n', fd);
	if (message)
		ft_putendl_fd(message, fd);
	ft_putendl_fd("Server has been terminated", fd);
	exit(status);
}

static void	send_confirmation(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
		terminate_server(1, "Error while sending confirmation");
}

static void	signal_handler(const int signum, siginfo_t *info, void *context)
{
	static char		buffer[BUFFER_SIZE + 1];
	static char		current_char;
	static size_t	m_index = 0;
	static size_t	char_index = 0;

	(void) context;
	if (signum == SIGINT)
		terminate_server(0, "CTRL+C has been pressed");
	current_char = current_char << 1 | (signum == SIGUSR2);
	if (++char_index == 8)
	{
		buffer[m_index] = current_char;
		++m_index;
		char_index = 0;
		if (current_char == '\0' || m_index == BUFFER_SIZE)
		{
			buffer[m_index] = '\0';
			ft_putstr_fd(buffer, 1);
			m_index = 0;
			if (current_char == '\0')
				send_confirmation(info->si_pid, SIGUSR2);
		}
	}
	usleep(50);
	send_confirmation(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1
		|| sigaction(SIGINT, &sa, NULL) == -1)
		terminate_server(1, "Error while setting signal handler");
	sigemptyset(&sa.sa_mask);
	ft_putstr_fd("Welcome to my server, my PID is ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
