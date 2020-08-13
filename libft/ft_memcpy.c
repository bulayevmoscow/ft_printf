/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 00:04:28 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/11 19:42:39 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)destptr;
	s1 = (unsigned char *)srcptr;
	if (!num || destptr == srcptr)
		return (destptr);
	while (i < num)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
