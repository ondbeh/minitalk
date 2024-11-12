/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:11:52 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:31:34 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ret_value;

	ret_value = 0;
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		ret_value = (unsigned char) *s1 - (unsigned char) *s2;
		if (ret_value != 0)
			return (ret_value);
		++s1;
		++s2;
		--n;
	}
	if ((*s1 == '\0' || *s2 == '\0') && n > 0)
		ret_value = (unsigned char) *s1 - (unsigned char) *s2;
	return (ret_value);
}
