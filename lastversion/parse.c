/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:00:54 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 13:53:36 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		parse_main(const char *str, va_list arg_list)
{
	int			ft_printf;

	model = push_mopdel(str, NULL, 1);
	parse_sec(str, arg_list);
	debug_struct();
	ft_printf = print_result();
	remove_struct();
	return (ft_printf);
}

int		print_result(void)
{
	int			len;
	int			i;
	t_model		*model1;

	model1 = model;
	model1 = model1->next;
	len = 0;
	while (model1)
	{
		i = 0;
		while (model1->str[i])
			ft_putchar(model1->str[i++]);
		len += i;
		if (model1->next == NULL)
			break ;
		model1 = model1->next;
	}
	return (len);
}

int		parse_sec(const char *str, va_list arg_list)
{
	int len[2];

	len[0] = 0;
	len[1] = 0;
	while (str[(len[1] + len[0])])
	{
		if (str[len[1] + len[0]] == '%')
		{
			push_mopdel(ft_strsub(str, len[0], len[1]), model, 02);
			len[1] += parse_pros((char *)str + (len[0] + len[1]), arg_list);
			len[0] += len[1];
			len[1] = 0;
		}
		else
			len[1]++;
	}
	push_mopdel(ft_strsub(str, len[0], len[1]), model, 022);
}

int		parse_pros(char *str, va_list arg_list)
{
	int			len;
	t_info		test;

	test = info_init();
	len = check_manager(str, &test);
	pusher_manager(&test, arg_list);
	return (len);
}

t_model	*push_mopdel(const char *str, t_model *model, int isnew)
{
	t_model		*model1;

	model1 = (t_model *)malloc(sizeof(t_model));
	model1->value = isnew;
	model1->str = (char *)str;
	model1->next = NULL;
	if (isnew == 1)
		return (model1);
	while (model->next != NULL)
		model = (t_model *)model->next;
	model->next = (t_model *)model1;
	return (model1);
}
