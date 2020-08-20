/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:43:54 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:43:55 by aghar            ###   ########.fr       */
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
