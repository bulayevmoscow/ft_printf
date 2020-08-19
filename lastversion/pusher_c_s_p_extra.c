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
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (-1);
	str[0] = (char )va_arg(arg_list, int);
	pusher_d_i_2(info, str);
//	push_mopdel(str, g_model, 125);
}

int		pusher_percent(t_info *info, va_list arg_list)
{
	char	*str;

	str = ft_strnew(2);
	if (str == NULL)
		return (-1);
	*str = '%';
	push_mopdel(str, g_model, 125, 0);
	return (0);
}
