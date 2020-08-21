/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:40:19 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/20 03:22:12 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
