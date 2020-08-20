/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:45:06 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/16 00:25:22 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	int					pos;
	unsigned long long	result;

	i = 0;
	pos = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos = -1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (result * pos);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		i++;
		if (result > 9223372036854775807 && pos == 1)
			return (-1);
		if (result > 9223372036854775807 && pos == -1)
			return (0);
	}
	return ((long long int)result * pos);
}
