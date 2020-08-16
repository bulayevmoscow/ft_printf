/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:27:41 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 02:46:04 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	stars_manager(t_info *info, va_list arg_list)
{
	if (info->width_mod == 2)
	{
		info->width = va_arg(arg_list, int);
		info->width_mod = 0;
	}
	if (info->precision_mod == 2)
	{
		info->precision = va_arg(arg_list, int);
		info->precision_mod = 0;
	}
}
