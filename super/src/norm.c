/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:59:55 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 22:20:22 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_spec_trans_x(unsigned long int a, int os)
{
	unsigned long int		i;
	int						*str;
	int						x;
	char					*str1;

	x = 0;
	str = (int *)malloc(sizeof(int) * 32);
	i = a;
	while (a >= (unsigned int)os)
	{
		i = a / os;
		str[x] = a - i * os;
		a = i;
		x++;
	}
	str[x] = i;
	str1 = ft_back_string(str, x, 6);
	free(str);
	return (str1);
}

char	*ft_spec_trans_xx(unsigned long int a, int os)
{
	unsigned long int		i;
	int						*str;
	int						x;
	char					*string;

	x = 0;
	str = (int *)malloc(sizeof(int) * 32);
	i = a;
	while (a >= (unsigned int)os)
	{
		i = a / os;
		str[x] = a - i * os;
		a = i;
		x++;
	}
	str[x] = i;
	string = ft_back_string(str, x, 1);
	free(str);
	return (string);
}

char	*ft_back_string(int *str, int x, int a)
{
	char					*string;
	int						i;
	int						f;
	int						h;

	string = ft_strnew(x + 1);
	i = 0;
	f = x;
	if (a == 1)
		h = 55;
	else
		h = 87;
	while (i <= (unsigned int)f)
	{
		if (str[x] > 9)
			string[i] = str[x] + h;
		else
			string[i] = str[x] + 48;
		--x;
		i++;
	}
	return (string);
}

void	pusher_string(t_info *info, va_list arg_list)
{
	char					*str;
	char					*import;

	info->flag_zero = (info->flag_minus) ? 0 : info->flag_zero;
	stars_manager(info, arg_list);
	if (NULL == (import = va_arg(arg_list, char *)) && info->precision_mod != 1)
	{
		if (info->pre == -1)
			str = ft_strdup("(null)");
		else
			str = ft_strsub("(null)", 0, info->pre);
	}
	else if (info->precision_mod == 1)
		str = ft_strnew(0);
	else if (info->precision_mod == 0 && info->pre != -1)
		str = ft_strsub(import, 0, info->pre);
	else if (info->precision_mod == 0 && info->pre == -1)
		str = ft_strdup(import);
	if (info->width)
		str = pusher_string_width(info, str);
	push_mopdel(str, g_model, 125, 0);
}

char	*pusher_string_width(t_info *info, char *str)
{
	int						len;
	char					*str1;
	int						i;

	i = -1;
	if ((int)ft_strlen(str) > info->width)
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
