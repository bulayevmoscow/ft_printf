//
// Created by Kudzu Psylocke on 8/14/20.
//
#include "../header/header.h"

int pusher_f(t_info *info, va_list arg_list)
{
	long int nbr1;
	long double nbr2;
	stars_manager(info, arg_list);
	pusher_f_split(&nbr1, &nbr2, info, arg_list);


	printf("\n[pusher_f]Get nbr_i = %ld nbr_d = %Lf", nbr1, nbr2);
}

//int pusher_u
void pusher_f_split(long *in, long double *de, t_info *info, va_list arg_list)
{
	char *str;
	int i;
	long double nbr;

	i = 0;
	nbr = (info->length == 0) ? va_arg(arg_list, double) : \
    va_arg(arg_list, long double);
	*in = (long int) nbr;
	*in = (long int) nbr;
	nbr -= *in;
	*de = nbr;

	info->precision = (info->precision == -1) ? 6 : info->precision;
	str = ft_strnew(info->precision);
	while (i != info->precision)
	{
		nbr *= 10;
		str[i++] = '0' + (int) nbr;
		nbr -= (long int)nbr;
	}

	printf("\n[pusher_f_split] Make str %s", str);
}
