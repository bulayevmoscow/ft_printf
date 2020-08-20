/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:27:41 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/20 15:49:34 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	stars_manager(t_info *info, va_list arg_list)
{
	if (info->width_mod == 2)
	{
		info->width = va_arg(arg_list, int);
		if (info->width <= 0)
		{
			info->width *= -1;
			info->flag_minus = 1;
		}
		info->width_mod = 0;
	}
	if (info->precision_mod == 2)
	{
		info->pre = va_arg(arg_list, int);
		if (info->pre < 0)
		{
			info->pre = -1;
		}
		info->precision_mod = 0;
	}
}
