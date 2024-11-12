/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:54:06 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:26 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isinset(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	prefix_len;
	size_t	postfix_len;
	size_t	s_len;

	prefix_len = 0;
	postfix_len = 0;
	s_len = ft_strlen(s1);
	while (prefix_len < s_len && ft_isinset(s1[prefix_len], set))
		++prefix_len;
	if (prefix_len == s_len)
		return (ft_calloc(1, 1));
	while (ft_isinset(s1[s_len - postfix_len - 1], set))
		++postfix_len;
	return (ft_substr (s1, prefix_len, s_len - prefix_len - postfix_len));
}
