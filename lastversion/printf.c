/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:48:45 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 13:55:50 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_printf(const char *input, ...)
{
	va_list	arg_list;

	va_start(arg_list, input);
	return (parse_main(input, arg_list));
}

t_info	info_init(void)
{
	t_info information;

	information.flag_zero = 0;
	information.flag_oct = 0;
	information.flag_plus = 0;
	information.flag_space = 0;
	information.flag_minus = 0;
	information.width = 0;
	information.width_mod = 0;
	information.precision = 0;
	information.precision_mod = 0;
	information.length = 0;
	information.specifier = 0;
	return (information);
}
