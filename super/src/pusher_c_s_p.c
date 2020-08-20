/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_c_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:11:23 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/20 22:00:59 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		pusher_manager(t_info *info, va_list arg_list)
{
	if (info->specifier == 'c')
		pusher_c(info, arg_list);
	if (info->specifier == '%')
		pusher_percent(info);
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

	stars_manager(info, arg_list);
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
	info->flag_plus = 0;
	str = ft_spec_trans_xx(nbr, 16);
	if (info->flag_oct && nbr != 0)
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
	info->flag_plus = 0;
	str = ft_spec_trans_x(nbr, 8);
	if (info->flag_oct && nbr != 0)
		str = ft_str_concat(ft_strdup("0"), 1, str, 1);
	pusher_d_i_2(info, str);
	return (0);
}
