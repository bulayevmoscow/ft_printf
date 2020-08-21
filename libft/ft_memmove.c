/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 01:58:52 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/10 03:12:50 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*getter;
	size_t			i;

	source = (unsigned char*)src;
	getter = (unsigned char*)dst;
	i = 0;
	if (source == getter)
		return (dst);
	if (source < getter)
		while (len-- > 0)
			getter[len] = source[len];
	else
		while (i < len)
		{
			getter[i] = source[i];
			i++;
		}
	return (dst);
}
