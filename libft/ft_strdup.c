/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:57:16 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/12 20:16:17 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
