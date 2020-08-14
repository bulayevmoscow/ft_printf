//
// Created by Kudzu Psylocke on 8/14/20.
//
#include <../header/header.h>

void	stars_manager(t_info *info, va_list arg_list)
{
	if (info->width_mod == 2)
	{
		info->width = va_arg(arg_list, int);
		info->width_mod = 0;
		printf("\ninfo->width_mod == 2");
	}
	if (info->precision_mod == 2)
	{
		info->precision = va_arg(arg_list, int);
		info->precision_mod = 0;
		printf("\tinfo->precision_mod == 2");
	}
}
