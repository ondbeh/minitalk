/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *d, const void *s, size_t count)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (d == NULL && s == NULL)
		return (d);
	dest = (unsigned char *) d;
	src = (const unsigned char *) s;
	i = 0;
	if (dest > src && dest < src + count)
	{
		while (count--)
			dest[count] = src[count];
	}
	else
	{
		while (i < count)
		{
			dest[i] = src[i];
			++i;
		}
	}
	return (d);
}
