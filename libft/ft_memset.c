/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:16:11 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/08 23:53:42 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *destination, int c, size_t n)
{
	size_t			i;
	unsigned char	*string_next;

	i = 0;
	string_next = destination;
	while (i < n)
	{
		string_next[i++] = c;
	}
	return (string_next);
}
