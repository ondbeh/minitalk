/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:14:17 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:29 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*curr_found;

	curr_found = NULL;
	ch = (char) c;
	while (*s)
	{
		if (*s == ch)
			curr_found = (char *) s;
		++s;
	}
	if (*s == ch)
		curr_found = (char *) s;
	return (curr_found);
}
