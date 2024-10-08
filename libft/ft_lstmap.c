/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:11:10 by joafaust          #+#    #+#             */
/*   Updated: 2024/09/20 16:21:55 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nnd;
	t_list	*l;

	l = NULL;
	while (lst)
	{
		nnd = ft_lstnew(f(lst->content));
		if (!nnd)
			del(nnd);
		else
			ft_lstadd_back(&l, nnd);
		lst = lst->next;
	}
	return (l);
}
/* Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed */