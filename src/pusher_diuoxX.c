#include "../header/header.h"

int pusher_d_i(t_info *info, va_list arg_list)
{
	char *str;
	long long int nbr;

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

	if (info->width_mod == 2) {
		info->width = va_arg(arg_list, int);
		info->width_mod = 0;
		printf("\ninfo->width_mod == 2");
	}
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
	if (ft_atoi(str) >= 0 && info->flag_space && !info->flag_plus)
		*pos = ' ';
	if (ft_atoi(str) >= 0 && info->flag_plus)
		*pos = '+';
	str1 = str;
	str = ft_strjoin(pos, str);
	free(pos);
	free(str);
	if (info->width)
		str = pusher_string_width(info, str1);
	while (str[++i] && info->flag_zero)
		if (str[i] == '+' || str[i] == '-') {
			str[0] = str[i];
			str[i] = '0';
		}
	printf("\n[pusher_d_i_2] Result is %s", str);
	pushModel(str, model, 225);
}
int pusher_d_i_2_flags(t_info *info, char *str){

}
