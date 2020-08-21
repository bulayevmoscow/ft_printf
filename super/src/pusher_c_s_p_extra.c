/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_c_s_p_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:54:33 by aghar             #+#    #+#             */
/*   Updated: 2020/08/21 16:43:32 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	pusher_c(t_info *info, va_list arg_list)
{
	char		chr;
	char		*str;

	stars_manager(info, arg_list);
	chr = (char)va_arg(arg_list, int);
	if (info->width)
	{
		str = ft_strmaker(info->flag_zero, info->width);
		if (info->width && info->flag_minus)
			str[0] = chr;
		if (info->width && !info->flag_minus)
			str[ft_strlen(str) - 1] = chr;
		push_mopdel(str, g_model, 12, info->width);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = chr;
		push_mopdel(str, g_model, 12, 1);
	}
}

int		pusher_percent(t_info *info)
{
	char		*str;

	info->flag_zero = (info->flag_minus) ? 0 : info->flag_zero;
	str = ft_strnew(2);
	if (str == NULL)
		return (-1);
	*str = '%';
	if (info->width > 0)
	{
		free(str);
		str = ft_strmaker(info->flag_zero, info->width);
		if (info->flag_minus)
			str[0] = '%';
		else
			str[info->width - 1] = '%';
	}
	push_mopdel(str, g_model, 125, 0);
	return (0);
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
