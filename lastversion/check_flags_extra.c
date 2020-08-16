/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:33:43 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 13:44:41 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_help(const char *str, t_info *info, int *len, int *precision)
{
	*len = 1;
	if (!ft_isdigit(*(str + 1)))
		info->precision_mod = 1;
	if (*(str + 1) == '*')
	{
		info->precision_mod = 2;
		return (-1);
	}
	*precision = ft_atoi(str + *len);
	while (ft_isdigit(*(str + *len)))
		len++;
	return (0);
}

int		check_precision(const char *str, t_info *info)
{
	int		len;
	int		precision;

	len = 0;
	precision = 0;
	if (*str == '.')
	{
		if (ft_help(str, info, &len, &precision) == -1)
			return (++len);
	}
	else
	{
		info->precision = -1;
		return (0);
	}
	if (precision != 0)
		info->precision = precision;
	else
		info->precision_mod = 1;
	return (len);
}

int		check_width(char *str, t_info *info)
{
	int		width;
	int		len;

	len = 0;
	if (*str == '*')
	{
		info->width_mod = 2;
		return (++len);
	}
	width = ft_atoi(str + len);
	info->width = width;
	if (width == 0)
		return (0);
	else
		while (ft_isdigit(*(str + len)))
			len++;
	return (len);
}
