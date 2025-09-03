/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:32:51 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/29 17:14:08 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*pointer;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		pointer = ft_lstnew(f(lst->content));
		if (!pointer)
			ft_lstclear(&head, del);
		ft_lstadd_back(&head, pointer);
		lst = lst->next;
	}
	return (head);
}
