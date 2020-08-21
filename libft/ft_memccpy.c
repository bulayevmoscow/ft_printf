/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:09:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/19 21:42:47 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)source;
	to = (unsigned char *)dest;
	while (count--)
	{
		*to++ = *from++;
		if (*(from - 1) == (unsigned char)ch)
			return (to);
	}
	return (NULL);
}
