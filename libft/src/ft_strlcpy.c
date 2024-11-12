/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:51:08 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:41 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		ret_value;
	size_t	i;

	i = 0;
	ret_value = 0;
	while (src[ret_value])
		ret_value++;
	while (i < size - 1 && src[i] && size)
	{
		dest[i] = src[i];
		++i;
	}
	if (size)
		dest[i] = '\0';
	return (ret_value);
}
