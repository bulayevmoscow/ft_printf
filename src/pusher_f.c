//
// Created by Kudzu Psylocke on 8/14/20.
//
#include "../header/header.h"

int pusher_f(t_info *info, va_list arg_list)
{
	long double nbr1;
	long double nbr2;
	stars_manager(info, arg_list);
	pusher_f_split(&nbr1, &nbr2, info, arg_list);


	printf("\n[pusher_f]Get nbr_i = %Lf nbr_d = %.20Lf", nbr1, nbr2);
}

//int pusher_u
int pusher_f_split(long double *in, long double *de, t_info *info,
				   va_list arg_list)
{
	char *str;
	int i;
	double long nbr;

	i = 0;
	nbr = (info->length != pf_L) ? (long double) va_arg(arg_list, double) : \
    va_arg(arg_list, long double);
	*in = (long int) nbr;
	nbr -= *in;
	*de = nbr = (nbr >= 0) ? nbr : nbr * -1;

	info->precision = (info->precision == -1) ? 6 : info->precision;
	str = ft_strnew(info->precision);
	if (str == NULL)
		return (-1);
	round_float(&nbr, info->precision);
	while (i != info->precision)
	{
		nbr *= 10;
		str[i++] = (char) ((nbr) + 48);
		nbr -= (long int) nbr;
	}
	printf("\n[pusher_f_split] Make str %s", str);
	return pusher_f_join(*in, str, info);

}

void round_float(long double *nbr, int precision)
{
	long double rang;

	if (precision > 19)
		return;
	rang = 5;

	while (precision + 1 != 0)
	{
		rang /= 10;
		precision--;
	}
	*nbr += rang;
	printf("\n[round_float]Rang = %.20Lf Sum = %.21Lf", rang, *nbr + rang);
}

int pusher_f_join(double long nbr1, char *nbr2, t_info *info)
{
	char *nbr;
	char pos;
	char *buff;

	pos = (nbr1 >= 0) ? 1 : -1;
	nbr = ft_itoa_external_unsgn((unsigned long long) nbr1 * pos);
	if (nbr == NULL)
		return (-1);
	if (pos == -1)
	{
		buff = nbr;
		nbr = ft_strjoin("-", nbr);
		if (nbr == NULL)
			return (-1);
		free(buff);
	}
	printf("\n[pusher_f_join]ft_strlen of nbr2 = %d", ft_strlen(nbr2));
	if ((ft_strlen(nbr2) == 0 && info->flag_oct) || ft_strlen(nbr2) > 0)
	{
		buff = nbr;
		nbr = ft_strjoin(nbr, ".");
		if (nbr == NULL)
			return (-1);
		free(buff);
	}
	buff = nbr;
	nbr = ft_strjoin(nbr, nbr2);
	if (nbr == NULL)
		return (-1);
	free(buff);
	free(nbr2);
	printf("\n[pusher_f_join][%d]nbr = %s",pos, nbr);
	return (pusher_d_i_2(info, nbr));
}
