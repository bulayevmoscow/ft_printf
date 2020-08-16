/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:48:45 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 02:45:34 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_printf(const char *input, ...)
{
	va_list	arg_list;

	va_start(arg_list, input);
	return (parseMain(input, arg_list));
}

t_info	info_init(void)
{
	t_info tInfo;

	tInfo.flag_zero = 0;
	tInfo.flag_oct = 0;
	tInfo.flag_plus = 0;
	tInfo.flag_space = 0;
	tInfo.flag_minus = 0;
	tInfo.width = 0;
	tInfo.width_mod = 0;
	tInfo.precision = 0;
	tInfo.precision_mod = 0;
	tInfo.length = 0;
	tInfo.specifier = 0;
	return (tInfo);
}
