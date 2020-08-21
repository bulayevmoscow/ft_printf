/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:14:10 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/12 23:23:41 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char*)s;
	while ((*a != (char)c) && *a)
		a++;
	if (*a == (char)c)
		return (a);
	return (NULL);
}
