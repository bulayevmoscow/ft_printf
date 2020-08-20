/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:47:51 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 22:20:05 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_printf(const char *input, ...)
{
	va_list	arg_list;

	va_start(arg_list, input);
	return (parse_main(input, arg_list));
}

t_info	info_init(void)
{
	t_info information;

	information.flag_zero = 0;
	information.flag_oct = 0;
	information.flag_plus = 0;
	information.flag_space = 0;
	information.flag_minus = 0;
	information.width = 0;
	information.width_mod = 0;
	information.pre = 0;
	information.precision_mod = 0;
	information.length = 0;
	information.specifier = 0;
	return (information);
}

char	*ft_strmaker(int space, int size)
{
	char					*str;
	int						i;

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
