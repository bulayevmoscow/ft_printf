//
// Created by paada on 30.07.2020.
//

#include "../header/header.h"

int ft_printf(const char *input, ...)
{
	debug = 0;
	va_list arg_list;

	va_start(arg_list, input);

	return parseMain(input, arg_list);
}

t_info info_init()
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
	return tInfo;
}
