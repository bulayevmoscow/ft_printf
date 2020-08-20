/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_c_s_p_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:55:57 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 14:03:25 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pusher_c(t_info *info, va_list arg_list)
{
	char	chr;
	char	*str;

	chr = (char )va_arg(arg_list, int);
	if (info->width)
	{
		str = ft_strmaker(info->flag_zero, info->width);
		if (info->width && info->flag_minus)
			str[0] = chr;
		if (info->width && !info->flag_minus)
			str[ft_strlen(str) - 1] = chr;
		push_mopdel(str, g_model, 12, info->width);
	} else
	{
		str = ft_strnew(1);
		str[0] = chr;
		push_mopdel(str, g_model, 12, 1);
	}



}

int		pusher_percent(t_info *info, va_list arg_list)
{
	char	*str;

	info->flag_zero = (info->flag_minus) ? 0 : info->flag_zero;
	str = ft_strnew(2);
	if (str == NULL)
		return (-1);
	*str = '%';
	if (info->width > 0)
	{
		free(str);
		str = ft_strmaker(info->flag_zero, info->width);
		if (info->flag_minus)
			str[0] = '%';
		else
			str[info->width - 1] = '%';
	}

	push_mopdel(str, g_model, 125, 0);
	return (0);
}
