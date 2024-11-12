/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:01:58 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:44 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	src_size = 0;
	dest_size = 0;
	i = 0;
	while (src[src_size])
		++src_size;
	while (dest[dest_size])
		++dest_size;
	if (size <= dest_size)
		return (src_size + size);
	while (src[i] && dest_size + i < size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[i + dest_size] = '\0';
	return (src_size + dest_size);
}
