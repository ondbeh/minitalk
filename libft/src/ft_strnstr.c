/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:51:28 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:31 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *) haystack);
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	i = 0;
	while (i < len && haystack[i])
	{
		if (i + needle_len > len)
			return (NULL);
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (j < needle_len && haystack[i + j] == needle[j])
				j++;
			if (j == needle_len)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
