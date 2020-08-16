/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:57:16 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:44:59 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	while (*s1 != '\0')
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 - i);
}
