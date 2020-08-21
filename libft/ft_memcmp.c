/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:31:10 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/12 00:01:48 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*frst;
	unsigned char	*scnd;
	size_t			i;

	frst = (unsigned char*)s1;
	scnd = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (frst[i] == scnd[i])
			i++;
		else
			return (frst[i] - scnd[i]);
	}
	return (0);
}
