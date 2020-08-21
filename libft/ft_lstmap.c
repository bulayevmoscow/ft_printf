/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:19:06 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/20 04:11:23 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *lst)
{
	t_list	*list_next;

	while (lst)
	{
		list_next = lst->next;
		free(lst->content);
		free(lst);
		lst = list_next;
	}
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list_new;
	t_list	*list_cur;

	if (!lst || !f)
		return (NULL);
	list_cur = f(lst);
	list_new = list_cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list_cur->next = f(lst)))
		{
			ft_free(list_cur);
			return (NULL);
		}
		list_cur = list_cur->next;
	}
	return (list_new);
}
