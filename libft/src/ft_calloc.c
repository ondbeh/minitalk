/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:40:30 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:55 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*return_ptr;

	return_ptr = malloc (num * size);
	if (return_ptr)
		ft_memset(return_ptr, 0, num * size);
	return (return_ptr);
}
