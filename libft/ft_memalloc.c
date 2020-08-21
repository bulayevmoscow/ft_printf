/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 00:26:37 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/16 01:03:43 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned char	*mem_temp;
	size_t			i;

	i = 0;
	mem = (void*)malloc(size);
	if (!mem)
		return (NULL);
	mem_temp = (unsigned char*)mem;
	while (i < size)
		mem_temp[i++] = 0;
	return (mem);
}
