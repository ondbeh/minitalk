/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:41:31 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:00 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putdigit_fd(int intdigit, int fd)
{
	char	c;

	if (intdigit < 0)
		intdigit = 0 - intdigit;
	c = '0' + intdigit;
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	number_array[11];
	int	position;

	position = 0;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
		number_array[0] = 1;
	else
		number_array[0] = 0;
	while (nb != 0)
	{
		number_array[++position] = nb % 10;
		nb = nb / 10;
	}
	if (number_array[0])
		ft_putchar_fd ('-', fd);
	while (position > 0)
	{
		ft_putdigit_fd (number_array[position], fd);
		--position;
	}
}
