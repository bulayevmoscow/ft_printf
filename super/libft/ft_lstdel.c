/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:36:22 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/20 01:43:56 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_list;
	t_list	*next_list;

	current_list = *alst;
	while (current_list)
	{
		next_list = current_list->next;
		del(current_list->content, current_list->content_size);
		free(current_list);
		current_list = next_list;
	}
	*alst = NULL;
}
