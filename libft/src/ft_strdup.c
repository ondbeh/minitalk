/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:50:59 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:51 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret_str;
	char	*tmp_ret_str;

	ret_str = (char *)malloc (sizeof (char) * (ft_strlen(src) + 1));
	if (ret_str == NULL)
		return (NULL);
	tmp_ret_str = ret_str;
	while (*src)
	{
		*tmp_ret_str = *src;
		++tmp_ret_str;
		++src;
	}
	*tmp_ret_str = '\0';
	return (ret_str);
}
