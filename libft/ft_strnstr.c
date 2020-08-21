/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:43:02 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/15 21:51:00 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		k = i;
		j = 0;
		if (haystack[i] == needle[j])
			while (haystack[i] == needle[j] && i++ < len)
				if (!needle[++j])
					return ((char*)haystack + k);
		i = k;
		i++;
	}
	return (NULL);
}
