#include "../header/header.h"

int pusher_d_i(t_info *info, va_list arg_list)
{
	char *str;
	long long int nbr;

	stars_manager(info, arg_list);
	if (info->length == 0)
		nbr = va_arg(arg_list, int);
	if (info->length == pf_hh)
		nbr = (signed char) va_arg(arg_list, int);
	if (info->length == pf_h)
		nbr = (short int) va_arg(arg_list, int);
	if (info->length == pf_l)
		nbr = va_arg(arg_list, long int);
	if (info->length == pf_ll)
		nbr = va_arg(arg_list, long long int);
	str = ft_itoa_external(nbr);
	printf("\n[pusher_d_i] Get number = %lld\nString is %s", nbr, str);
	pusher_d_i_2(info, str);
}

int pusher_d_i_2(t_info *info, char *str)
{
	char *pos;
	char *str1;
	int i;

	i = -1;
	pos = ft_strnew(1);
	if (!((str[0] == '-' || str[0] == '+') &&
		  ft_strlen(str) > info->precision) && \
    !((str[0] != '-' && str[0] != '+') && ft_strlen(str) >= info->precision) &&
		info->precision != -1)
		str = pusher_d_i_2_precision(info, str);

	if (ft_atoi(str) >= 0 && info->flag_space && !info->flag_plus)
		*pos = ' ';
	if (ft_atoi(str) >= 0 && info->flag_plus)
		*pos = '+';

	printf("\n[pusher_d_i_2][0] Result is %s", str);
	str1 = str;
	str = ft_strjoin(pos, str);

	printf("\n[pusher_d_i_2][1] Result is %s", str);

	info->flag_zero = (info->precision != -1 || info->flag_minus) ? 0
																  : info->flag_zero;
	if (info->width)
		str = pusher_string_width(info, str);
	while (str[++i] && info->flag_zero)
		if ((str[i] == '+' || str[i] == '-') && i != 0)
		{
			str[0] = str[i];
			str[i] = '0';
		}
	printf("\n[pusher_d_i_2][2] Result is %s", str);
	free(str1);
	free(pos);
	pushModel(str, model, 225);
}

char *pusher_d_i_2_precision(t_info *info, char *str)
{
	char *str1;
	int i;

	i = -1;
	printf("\n[pusher_d_i_2_precision]Get str %s", str);
	info->flag_zero = 0;
	printf("\nstlen = %zu", ft_strlen(str));
	str1 = ft_strmaker(1, info->precision);
	while (str[++i])
		str1[info->precision - ft_strlen(str) + i] = str[i];
	printf("\n[pusher_d_i_2_precision]Result is %s", str1);
	free(str);
	return (str1);

}

int pusher_u(t_info *info, va_list arg_list)
{
	char *str;
	unsigned long long int nbr;

	stars_manager(info, arg_list);
	if (info->length == 0)
		nbr = va_arg(arg_list, unsigned int);
	if (info->length == pf_hh)
		nbr = (unsigned char) va_arg(arg_list, unsigned int);
	if (info->length == pf_h)
		nbr = (unsigned short int) va_arg(arg_list, unsigned int);
	if (info->length == pf_l)
		nbr = va_arg(arg_list, unsigned long int);
	if (info->length == pf_ll)
		nbr = va_arg(arg_list, unsigned long long int);
	info->flag_space = 0;
	info->flag_plus = 0;
	str = ft_itoa_external_unsgn(nbr);

	printf("\n[pusher_u]Get number = %lld\nString is %s", nbr, str);
	return pusher_d_i_2(info, str);
}
