/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_c_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:11:23 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/20 13:44:46 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int		pusher_manager(t_info *info, va_list arg_list)
{
	if (info->specifier == 'c')
		pusher_c(info, arg_list);
	if (info->specifier == '%')
		pusher_percent(info, arg_list);
	if (info->specifier == 's')
		pusher_string(info, arg_list);
	if (info->specifier == 'd' || info->specifier == 'i')
		pusher_d_i(info, arg_list);
	if (info->specifier == 'u')
		pusher_u(info, arg_list);
	if (info->specifier == 'f')
		pusher_f(info, arg_list);
	if (info->specifier == 'x')
		pusher_x(info, arg_list);
	if (info->specifier == 'o')
		pusher_o(info, arg_list);
	if (info->specifier == 'X')
		pusher_xx(info, arg_list);
	if (info->specifier == 'p')
		pusher_p(info, arg_list);
	return (0);
}

int		pusher_x(t_info *info, va_list arg_list)
{
	char					*str;
	unsigned long long int	nbr;

	str = NULL;

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
	str = ft_spec_trans_x(nbr, 16);
	if (info->flag_oct && nbr != 0)
		str = ft_str_concat(ft_strdup("0x"), 1, str, 1); 
	pusher_d_i_2(info, str);
	return (0);
}

int		pusher_p(t_info *info, va_list arg_list)
{
	char					*str;
	unsigned long long int	nbr;

	nbr = (unsigned long int)va_arg(arg_list, void *);
	str = ft_spec_trans_x(nbr, 16);
	str = ft_str_concat(ft_strdup("0x"), 1, str, 1);
	pusher_d_i_2(info, str);
	return (0);
}

int		pusher_xx(t_info *info, va_list arg_list)
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
	info->flag_plus = 0;;
	str = ft_spec_trans_xx(nbr, 16);
	if (info->flag_oct)
		str = ft_str_concat(ft_strdup("0X"), 1, str, 1);
	pusher_d_i_2(info, str);
	return (0);
}

int		pusher_o(t_info *info, va_list arg_list)
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
	info->flag_plus = 0;;
	str = ft_spec_trans_x(nbr, 8);
	if (info->flag_oct && nbr != 0)
		str = ft_str_concat(ft_strdup("0"), 1, str, 1);
	pusher_d_i_2(info, str);
	return (0);
}

char    *ft_spec_trans_x(unsigned long int a, int os)
{
    unsigned long int     i;
    int     *str;
    int     x;
	int		f;
	char	*str1;

    x = 0;
    str = (int *)malloc(sizeof(int) * 32);
	i = a;
    while (a >= os)
    {
        i = a / os;
        str[x] = a - i * os;
        a = i;
        x++;
    }
    str[x] = i;
	i = 0;
	str1 = ft_strnew(x + 1);
	f = x;
    while (i <= f)
    {
        if (str[x] > 9)
		{
			str1[i] = str[x] + 87;
		}
        else
		{
			str1[i] = str[x] + '0';
		}
        --x;
		i++;
    }
	free(str);
    return (str1);
}

char    *ft_spec_trans_xx(unsigned long int a, int os)
{
    unsigned long int     i;
    int     *str;
    int     x;
    char    *string;
	int		f;
	
    x = 0;
    str = (int *)malloc(sizeof(int) * 32);
	i = a;
    while (a >= os)
    {
        i = a / os;
        str[x] = a - i * os;
        a = i;
        x++;
    }
    str[x] = i;
	i = 0;
    string = ft_strnew(x + 1);
	f = x;
    while (i <= f)
    {
        if (str[x] > 9)
            string[i] = str[x] + 55;
        else
            string[i] = str[x] + 48;
        --x;
		i++;
    }
	free(str);
    return (string);
}

int		pusher_string(t_info *info, va_list arg_list)
{
	char	*str;
	char	*import;
	char	*buffer;

	info->flag_zero = (info->flag_minus) ? 0 : info->flag_zero;
	stars_manager(info, arg_list);
	if (NULL == (import = va_arg(arg_list, char *)) && info->precision_mod != 1)
	{
		if (info->precision == -1)
			str = ft_strdup("(null)");
		else
			str = ft_strsub("(null)", 0, info->precision);
	}

	else if (info->precision_mod == 1)
		str = ft_strnew(0);
	else if (info->precision_mod == 0 && info->precision != -1)
		str = ft_strsub(import, 0, info->precision);
	else if (info->precision_mod == 0 && info->precision == -1)
		str = ft_strdup(import);
	if (info->width)
		str = pusher_string_width(info, str);
	push_mopdel(str, g_model, 125, 0);
}

char	*pusher_string_width(t_info *info, char *str)
{
	int		len;
	char	*str1;
	int		i;

	i = -1;
	if (ft_strlen(str) > info->width)
		return (str);
	len = info->width;
	str1 = ft_strmaker((info->flag_zero), len);
	if (!str1)
		return (NULL);
	while (str[++i] && info->flag_minus)
		str1[i] = str[i];
	i--;
	while (str[++i] && !info->flag_minus)
		str1[len - ft_strlen(str) + i] = str[i];
	free(str);
	return (str1);
}

char	*ft_strmaker(int space, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i != size)
	{
		str[i] = (space) ? '0' : ' ';
		i++;
	}
	str[size] = '\0';
	return (str);
}
