/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:44:34 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:44:35 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_str_concat(char *str1, int d1, char *str2, int d2)
{
	char	*str3;
	size_t	len;
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (NULL == str1 || NULL == str2 || 0 == (len = ft_strlen(str1) +
			ft_strlen(str2)) || NULL == (str3 = ft_strnew(len)))
		return (NULL);
	while (i[0] + i[1] != len)
		str3[i[2]++] = (char)((str1[i[0]]) ? str1[i[0]++] : str2[i[1]++]);
	if (d1)
	{
		free(str1);
		str1 = NULL;
	}
	if (d2)
	{
		free(str2);
		str2 = NULL;
	}
	return (str3);
}
