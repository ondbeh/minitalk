/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:54:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:13 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *d, const void *s, size_t count)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (d == NULL && s == NULL)
		return (d);
	dest = (unsigned char *) d;
	src = (const unsigned char *) s;
	while (count--)
	{
		*dest = *src;
		++dest;
		++src;
	}
	return (d);
}
