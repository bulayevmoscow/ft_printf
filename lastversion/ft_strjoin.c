/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:40:19 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:44:58 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*sr;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	sr = ft_strnew(i);
	if (!sr)
		return (NULL);
	while (*s1)
		*sr++ = *s1++;
	while (*s2)
		*sr++ = *s2++;
	*sr = '\0';
	return (sr - i);
}
