/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:42:57 by obehavka          #+#    #+#             */
/*   Updated: 2024/10/19 12:32:33 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_next;

	while (*lst)
	{
		tmp_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_next;
	}
	free(*lst);
	*lst = NULL;
}
