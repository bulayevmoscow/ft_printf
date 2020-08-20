/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:44:58 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:44:59 by aghar            ###   ########.fr       */
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
