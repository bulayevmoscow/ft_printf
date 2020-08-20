/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:45:38 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:45:39 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
