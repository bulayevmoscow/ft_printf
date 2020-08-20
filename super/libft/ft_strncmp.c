/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:29:16 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/15 22:42:34 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	n1;

	i = 0;
	n1 = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && (s2[i] == s1[i]) && (n1 + 1 != n))
	{
		n1++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
