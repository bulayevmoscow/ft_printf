#include "header.h"

int		pusher_d_i(t_info *info, va_list arg_list)
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

int		pusher_d_i_2(t_info *info, char *str)
{
	int		i;

	i = -1;

	if (ft_atoi(str) >= 0 && info->flag_space && !info->flag_plus)
		str = ft_str_concat(" ", 0, str, 1);
	else if (ft_atoi(str) >= 0 && info->flag_plus)
		str = ft_str_concat("+", 0, str, 1);
	if (str[0] == ' ' || str[0] == '+' || str[0] == '-')
		info->precision++;
	if (info->precision != -1 && ft_strlen(str) < info->precision)
		str = ft_str_concat(ft_strmaker(1, info->precision - ft_strlen(str))\
		, 1, str, 1);
	while (str[++i] && str[0] != '+' && str[0] != '-')
		if ((str[i] == '+' || str[i] == '-' || str[i] == ' ') && i != 0)
		{
			str[0] = str[i];
			str[i] = '0';
		}
	if (ft_atoi(str) == 0 && info->precision_mod == 1 )
	{
		free(str);
		str = ft_strdup("");
	}
	info->flag_zero = (info->flag_minus || info->precision > 1) ? 0 : info->flag_zero;
	pusher_d_i_2_precision(info, &str);
	if (str == NULL)
		return (-1);
	push_mopdel(str, g_model, 10, 0);
	return 0;
}

void		pusher_d_i_2_precision(t_info *info, char **str)
{
	int		i;


	i = 0;
	if (info->width > ft_strlen(*str))
		*str = (info->flag_minus) ? \
		ft_str_concat(*str, 1, ft_strmaker(info->flag_zero, \
		info->width - (int)ft_strlen(*str)), 1) : \
		ft_str_concat(ft_strmaker(info->flag_zero, \
		info->width - (int)ft_strlen(*str)), 1, *str, 1);
	while ((*str)[i] && str[0][0] != ' ')
	{
		if (((*str)[i] == '+' || (*str)[i] == '-' ) && i != 0)
		{
			(*str)[0] = (*str)[i];
			(*str)[i] = '0';
		}
		i++;
	}

}

int		pusher_u(t_info *info, va_list arg_list)
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
