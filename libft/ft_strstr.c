/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:59:09 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/14 00:03:24 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i] && needle[j])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (!needle[j + 1])
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
