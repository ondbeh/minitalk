/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:11:30 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:36 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_str;
	size_t	i;

	ret_str = ft_strdup(s);
	i = 0;
	if (ret_str)
	{
		while (ret_str[i])
		{
			ret_str[i] = (f)(i, ret_str[i]);
			++i;
		}
	}
	return (ret_str);
}
