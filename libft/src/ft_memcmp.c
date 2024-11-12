/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:12 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:16 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			ret_value;
	const char	*str1;
	const char	*str2;

	str1 = (const char *) s1;
	str2 = (const char *) s2;
	ret_value = 0;
	while (n--)
	{
		ret_value = (unsigned char) *str1 - (unsigned char) *str2;
		if (ret_value != 0)
			return (ret_value);
		++str1;
		++str2;
	}
	return (ret_value);
}
