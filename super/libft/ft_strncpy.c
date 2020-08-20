/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:28:03 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/12 20:45:56 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t len1;

	len1 = 0;
	while (len1 < len && src[len1] != '\0')
	{
		dst[len1] = src[len1];
		len1++;
	}
	while (len1 < len)
		dst[len1++] = '\0';
	return (dst);
}
