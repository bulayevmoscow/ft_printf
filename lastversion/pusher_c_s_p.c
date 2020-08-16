/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher_c_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:11:23 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 13:56:36 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	return (0);
}

int		pusher_string(t_info *info, va_list arg_list)
{
	char	*str;
	char	*import;

	if (NULL == (import = va_arg(arg_list, char *)))
		return (-1);
	stars_manager(info, arg_list);
	if (info->precision_mod == 1)
		str = ft_strnew(0);
	if (info->precision_mod == 0 && info->precision != -1)
		str = ft_strsub(import, 0, info->precision);
	if (info->precision_mod == 0 && info->precision == -1)
		str = ft_strdup(import);
	if (info->width)
		str = pusher_string_width(info, str);
	push_mopdel(str, model, 125);
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
