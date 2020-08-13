/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:37:24 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/13 00:03:36 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*source;

	source = (char*)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (source[i] == (char)c)
			return (source + i);
		i--;
	}
	return (NULL);
}
