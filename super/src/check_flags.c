/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:41:04 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:41:05 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_manager(char *str, t_info *info)
{
	int		len;
	int		spec;

	len = 1;
	len += check_flag(str, info);
	len += check_width(str + len, info);
	len += check_precision(str + len, info);
	len += check_length(str + len, info);
	spec = check_specifier(str + len, info);
	if (spec == -1)
	{
		push_mopdel(ft_strsub(str, 0, 1), g_model, 4, 0);
		info->specifier = 0;
		return (len);
	}
	return (spec + len);
}

int		check_flag(char *str, t_info *info)
{
	int		len;

	len = 0;
	while (*(str + len + 1))
	{
		if (*(str + len + 1) == ' ')
			info->flag_space = 1;
		else if (*(str + len + 1) == '-')
			info->flag_minus = 1;
		else if (*(str + len + 1) == '+')
			info->flag_plus = 1;
		else if (*(str + len + 1) == '#')
			info->flag_oct = 1;
		else if (*(str + len + 1) == '0')
			info->flag_zero = 1;
		else
			break ;
		len++;
	}
	return (len);
}

int		check_length(const char *str, t_info *info)
{
	if (*str == 'j')
		info->length = PF_J;
	if (*str == 'z')
		info->length = PF_Z;
	if (*str == 't')
		info->length = PF_T;
	if (*str == 'L')
		info->length = PF_Y;
	if (info->length != 0)
		return (1);
	return (check_length_ext(str, info));
}

int		check_length_ext(const char *str, t_info *info)
{
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
		{
			info->length = PF_HH;
			return (2);
		}
		info->length = PF_H;
		return (1);
	}
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
		{
			info->length = PF_LL;
			return (2);
		}
		info->length = PF_L;
		return (1);
	}
	return (0);
}

int		check_specifier(const char *str, t_info *info)
{
	if (*(str) == 'd' || *(str) == 'i' || *(str) == 'u' || *(str) == 'o' ||
	*(str) == 'x' || *(str) == 'X' || *(str) == 'f' || *(str) == 'F' ||
	*(str) == 'E' || *(str) == 'e' || *(str) == 'g' || *(str) == 'G' ||
	*(str) == 'a' || *(str) == 'A' || *(str) == 'c' || *(str) == 's' ||
	*(str) == 'p' || *(str) == 'n' || *(str) == '%')
	{
		info->specifier = *str;
	}
	else if (*(str) == '%')
		return (-2);
	else
		return (-1);
	return (1);
}
