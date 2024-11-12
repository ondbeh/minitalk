/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:21:18 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:47 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*return_str;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	return_str = (char *) malloc (total_size + 1);
	if (!return_str)
		return (NULL);
	ft_strlcpy(return_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(return_str, s2, total_size + 1);
	return (return_str);
}
