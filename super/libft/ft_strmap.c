/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:56:27 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/16 23:03:48 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;

	if (!s || !f)
		return (NULL);
	s1 = ft_strnew(ft_strlen(s));
	if (!s1)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	return (s1);
}
