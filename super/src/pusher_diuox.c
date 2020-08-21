/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_diuox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:56:10 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 22:03:58 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		pusher_d_i(t_info *info, va_list arg_list)
{
	char					*str;
	long long int			nbr;

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

void	pusher_d_i_2_1(t_info *info, char **str)
{
	int	i;

	i = -1;
	if (ft_atoi((*str)) >= 0 && info->flag_space && !info->flag_plus)
		(*str) = ft_str_concat(" ", 0, (*str), 1);
	else if (ft_atoi((*str)) >= 0 && info->flag_plus)
		(*str) = ft_str_concat("+", 0, (*str), 1);
	if ((*str)[0] == ' ' || (*str)[0] == '+' || (*str)[0] == '-')
		info->pre++;
	if (info->pre != -1 && (int)ft_strlen((*str)) < info->pre)
		(*str) = ft_str_concat(ft_strmaker(1, info->pre -
		(int)ft_strlen(*str)), 1, (*str), 1);
	while ((*str)[++i] && (*str)[0] != '+' && (*str)[0] != '-')
		if (((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ') && i != 0)
		{
			(*str)[0] = (*str)[i];
			(*str)[i] = '0';
		}
}

int		pusher_d_i_2(t_info *info, char *str)
{

	pusher_d_i_2_1(info, &str);

	while (ft_atoi(str) == 0 && info->precision_mod == 1)
	{
		if (info->specifier == 'o' && info->flag_oct == 1)
			break ;
		free(str);
		str = (info->specifier == 'p' && info->pre != -1) ? ft_strdup("0x") : ft_strdup("");
//		ft_strdup("");

		break ;
	}
	info->flag_zero = (info->flag_minus || info->pre > 1) ? 0 : info->flag_zero;
	pusher_d_i_2_precision(info, &str);
	if (str == NULL)
		return (-1);
	push_mopdel(str, g_model, 10, 0);
	return (0);
}

void	pusher_d_i_2_precision_2(t_info *info, char **str)
{
	int						i;

	i = 0;
	if ((info->specifier == 'x' || info->specifier == 'X') && info->flag_zero)
		while ((*str)[++i])
			if (((*str)[i] == 'x' || (*str)[i] == 'X') && i > 1)
			{
				(*str)[1] = (*str)[i];
				(*str)[i] = '0';
			}
	i = 0;
	if (info->width > 0 && info->flag_space)
		while ((*str)[i])
		{
			if ((*str)[i] == ' ' && i != 0)
			{
				(*str)[0] = (*str)[i];
				(*str)[i] = (info->flag_zero) ? '0' : ' ';
			}
			i++;
		}
}

void	pusher_d_i_2_precision(t_info *info, char **str)
{
	int						i;

	i = 0;
	if (info->width > (int)ft_strlen(*str))
		*str = (info->flag_minus) ? \
		ft_str_concat(*str, 1, ft_strmaker(info->flag_zero, \
		info->width - (int)ft_strlen(*str)), 1) : \
		ft_str_concat(ft_strmaker(info->flag_zero, \
		info->width - (int)ft_strlen(*str)), 1, *str, 1);
	while ((*str)[i] && (*str)[0] != ' ')
	{
		if (((*str)[i] == '+' || (*str)[i] == '-') && i != 0)
		{
			(*str)[0] = (*str)[i];
			(*str)[i] = '0';
		}
		i++;
	}
	pusher_d_i_2_precision_2(info, str);
}
