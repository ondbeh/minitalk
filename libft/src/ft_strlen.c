/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:03:43 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/09 15:37:12 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	strlen;

	strlen = 0;
	while (*str != '\0')
	{
		++strlen;
		++str;
	}
	return (strlen);
}
