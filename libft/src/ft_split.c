/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:52:39 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:55 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s && *s == c)
		++s;
	while (*s)
	{
		while (*s && *s != c)
			++s;
		++word_count;
		while (*s && *s == c)
			++s;
	}
	return (word_count);
}

static char	**ft_killsplit(char **split)
{
	char	**tmp_ptr;

	tmp_ptr = split;
	while (*tmp_ptr)
	{
		free (*tmp_ptr);
		++tmp_ptr;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_size;
	size_t	word_count;
	char	**ret_ptr;
	char	**tmp_ptr;

	word_count = ft_word_count(s, c);
	ret_ptr = ft_calloc (sizeof (char *), (word_count + 1));
	if (!ret_ptr)
		return (NULL);
	tmp_ptr = ret_ptr;
	while (word_count--)
	{
		word_size = 0;
		while (*s == c)
			++s;
		while (s[word_size] && s[word_size] != c)
			++word_size;
		*tmp_ptr = ft_substr(s, 0, word_size);
		if (!*tmp_ptr)
			return (ft_killsplit(ret_ptr));
		++tmp_ptr;
		s += word_size;
	}
	return (ret_ptr);
}
