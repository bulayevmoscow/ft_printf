/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:27:41 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/20 14:47:12 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	stars_manager(t_info *info, va_list arg_list)
{
	// int a;
	// a = va_arg(arg_list, int);
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
		info->precision = va_arg(arg_list, int);
		if (info->precision <= 0)
		{
			info->precision *= -1;
			info->flag_minus = 1;
		}
		info->precision_mod = 0;
	}
}
