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
#include <string.h>

static void	signal_handler(const int signum)
{
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	m_index = 0;
	static size_t	char_index = 0;

	if (signum == SIGUSR1)
		buffer[m_index] = buffer[m_index] << 1;
	else
		buffer[m_index] = (buffer[m_index] << 1) | 1;
	++char_index;
	if (char_index == 8)
	{
		++m_index;
		char_index = 0;
	}
	if (m_index == BUFFER_SIZE
		|| (char_index == 0 && buffer[m_index - 1] == '\0'))
	{
		m_index = 0;
		ft_putstr_fd(buffer, 1);
		ft_memset(buffer, 0, BUFFER_SIZE);
	}
}

int	main(void)
{
	printf("Welcome to my server, my PID is %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
