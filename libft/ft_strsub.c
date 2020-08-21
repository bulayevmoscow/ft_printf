/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:04:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/17 00:28:51 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
