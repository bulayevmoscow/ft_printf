/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:51:44 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/09 00:02:37 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*string_next;

	i = 0;
	string_next = s;
	while (i < n)
	{
		string_next[i] = 0;
		i++;
	}
}
