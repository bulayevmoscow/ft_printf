/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:13:31 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/20 03:05:53 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *a;

	a = (t_list*)malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	if (!content)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		a->content = (void*)malloc(content_size);
		a->content = ft_memcpy(a->content, content, content_size);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}
