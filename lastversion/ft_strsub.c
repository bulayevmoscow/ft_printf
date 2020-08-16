/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:04:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:44:56 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = ft_strnew(len);
	if (!s1)
		return (NULL);
	return ((char *)ft_memcpy(s1, s + start, len));
}
