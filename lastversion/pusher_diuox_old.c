#include "header.h"

__unused int		pusher_d_i(t_info *info, va_list arg_list)
{
	char			*str;
	long long int	nbr;

	stars_manager(info, arg_list);
	if (info->length == 0)
		nbr = va_arg(arg_list, int);
	if (info->length == PF_HH)
		nbr = (signed char)va_arg(arg_list, int);
	if (info->length == PF_H)
		nbr = (short int)va_arg(arg_list, int);
	if (info->length == PF_L)
		nbr = va_arg(arg_list, long int);
	if (info->length == PF_LL)
		nbr = va_arg(arg_list, long long int);
	str = ft_itoa_external(nbr);
	pusher_d_i_2(info, str);
	return (0);
}

__unused void	ft_helpagain(char **str, t_info *info, char **pos)
{
	if (!(((*str[0]) == '-' || *str[0] == '+') &&
	ft_strlen(str) > info->precision) && \
	!((*str[0] != '-' && *str[0] != '+')
	&& ft_strlen(*str) >= info->precision) &&
		info->precision != -1)
		str = pusher_d_i_2_precision(info, str);
	if (ft_atoi(str) >= 0 && info->flag_space && !info->flag_plus)
		*pos = ' ';
	if (ft_atoi(str) >= 0 && info->flag_plus)
		*pos = '+';
}

__unused int		pusher_d_i_2(t_info *info, char *str)
{
	char	*pos;
	char	*str1;
	int		i;
	printf("\n\"%s\"", str);
	i = -1;
	pos = ft_strnew(1);
	ft_helpagain(&str, info, &pos);
	printf("\n\"%s\"", str);
	str = ft_str_concat(pos, 1, str, 1);
	printf("\n\"%s\"", str);
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
	if (info->precision != -1)
		str = pusher_d_i_2_precision(info, str);

	push_mopdel(ft_strdup(str), g_model, 225);
	return (0);
}

__unused char	*pusher_d_i_2_precision(t_info *info, char *str)
{
	char	*str1;
	int		i;

	i = -1;
	info->flag_zero = 0;
	str1 = ft_strmaker(1, info->precision);
	while (str[++i])
		str1[info->precision - ft_strlen(str) + i] = str[i];
	free(str);
	return (str1);
}

__unused int		pusher_u(t_info *info, va_list arg_list)
{
	char					*str;
	unsigned long long int	nbr;

	stars_manager(info, arg_list);
	if (info->length == 0)
		nbr = va_arg(arg_list, unsigned int);
	if (info->length == PF_HH)
		nbr = (unsigned char)va_arg(arg_list, unsigned int);
	if (info->length == PF_H)
		nbr = (unsigned short int)va_arg(arg_list, unsigned int);
	if (info->length == PF_L)
		nbr = va_arg(arg_list, unsigned long int);
	if (info->length == PF_LL)
		nbr = va_arg(arg_list, unsigned long long int);
	info->flag_space = 0;
	info->flag_plus = 0;
	str = ft_itoa_external_unsgn(nbr);
	return (pusher_d_i_2(info, str));
}