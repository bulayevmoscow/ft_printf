/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:11:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:44:57 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (i < size + 1)
		s[i++] = '\0';
	return (s);
}
