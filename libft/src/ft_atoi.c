/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:23:29 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	ret_int;
	int	is_positive;
	int	digit;

	is_positive = 1;
	ret_int = 0;
	while (ft_iswhitespace (*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive *= (-1);
		++str;
	}
	while (ft_isdigit (*str))
	{
		digit = *str - '0';
		ret_int *= 10;
		ret_int -= digit;
		++str;
	}
	return (ret_int * is_positive * (-1));
}
