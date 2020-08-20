/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:27:49 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/17 23:36:50 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	min;
	size_t	max;
	char	*sr;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	min = 0;
	while (s[min] == ' ' || s[min] == '\t' || s[min] == '\n')
		min++;
	while ((min < max) && (s[max - 1] == ' ' || s[max - 1] == '\t' ||
	s[max - 1] == '\n'))
		max--;
	if (max == min)
		return (ft_strnew(1));
	sr = ft_strsub(s, min, (max - min));
	return (sr);
}
