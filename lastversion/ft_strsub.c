/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:45:56 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:45:57 by aghar            ###   ########.fr       */
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
