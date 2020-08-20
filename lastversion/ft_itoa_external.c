/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:42:34 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:45:04 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_itoa_external_len(long long int n)
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
	unsigned long	tmp;

	len = ft_itoa_external_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = n * -1;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = (char)(tmp % 10 + '0');
	while (tmp /= 10)
		s[--len] = (char)(tmp % 10 + '0');
	if (n < 0)
		s[0] = '-';
	return (s);
}




int		ft_itoa_external_unsgn_len(unsigned long long int n)
{
	size_t					i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_external_unsgn(unsigned long long int n)
{
	char					*s;
	size_t					len;
	unsigned long long int	tmp;

	len = ft_itoa_external_unsgn_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = (char)(tmp % 10 + '0');
	while (tmp /= 10)
		s[--len] = (char)(tmp % 10 + '0');
	if (n < 0)
		s[0] = '-';
	return (s);
}
