/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:56 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:00:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr_lst;

	if (!f || !del || !lst)
		return (NULL);
	ptr_lst = NULL;
	while (lst)
	{
		ptr = ft_lstnew(f(lst->content));
		if (!ptr)
		{
			ft_lstclear(&ptr_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&ptr_lst, ptr);
		lst = lst->next;
	}
	return (ptr_lst);
}
