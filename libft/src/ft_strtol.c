/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:11:27 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/01 11:12:48 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_strtol(char *str, char **endptr)
{
	long	ret_int;
	int		is_positive;
	int		digit;

	is_positive = 1;
	ret_int = 0;
	while (ft_iswhitespace(*str))
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
	*endptr = str;
	return (ret_int * is_positive * (-1));
}
