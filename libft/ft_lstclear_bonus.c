/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:20:56 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/28 18:40:21 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*lst_next;

	if (!lst || !*lst || !del)
		return ;
	last = *lst;
	while (last)
	{
		lst_next = last->next;
		ft_lstdelone(last, del);
		last = lst_next;
	}
	*lst = NULL;
}
