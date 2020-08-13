/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:42:34 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/20 00:43:10 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

static int		ft_itoa_external_len(long long int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_external(long long int n)
{
	char			*s;
	size_t			len;
	long long int	tmp;

	len = ft_itoa_external_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		s[--len] = tmp % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
