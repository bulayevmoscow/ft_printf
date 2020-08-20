/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:45:12 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:45:13 by aghar            ###   ########.fr       */
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
