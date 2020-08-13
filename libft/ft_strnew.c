/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:11:39 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/17 21:26:44 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
