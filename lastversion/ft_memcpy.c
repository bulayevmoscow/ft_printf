/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 00:04:28 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:50:58 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
