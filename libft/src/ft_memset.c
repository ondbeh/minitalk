/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:10:09 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:09 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	fill_bit;
	unsigned char	*mem_ptr;

	fill_bit = (unsigned char) c;
	mem_ptr = (unsigned char *) b;
	while (len--)
	{
		*mem_ptr = fill_bit;
		++mem_ptr;
	}
	return (b);
}
