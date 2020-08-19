/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:00:54 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 14:13:52 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		parse_main(const char *str, va_list arg_list)
{
	int			ft_printf;

	g_model = push_mopdel(str, NULL, 1 , 0);
	parse_sec(str, arg_list);
	debug_struct();
	ft_printf = print_result();

	remove_struct();
//	exit(1);
	return (ft_printf);
}

int		print_result(void)
{
	int			len;
	int			i;
	t_model		*model1;

	model1 = g_model;
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
			push_mopdel(ft_strsub(str, len[0], len[1]), g_model, 02, 0);
			len[1] += parse_pros((char *)str + (len[0] + len[1]), arg_list);
			len[0] += len[1];
			len[1] = 0;
		}
		else
			len[1]++;
	}
	push_mopdel(ft_strsub(str, len[0], len[1]), g_model, 022, 0);
	return (0);
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

t_model	*push_mopdel(const char *str, t_model *g_model, int isnew, int len)
{
	t_model		*model1;

	model1 = (t_model *)malloc(sizeof(t_model));
	model1->value = isnew;
	model1->str = str;
	model1->next = NULL;
	if (isnew == 1)
		return (model1);
	while (g_model->next != NULL)
		g_model = (t_model *)g_model->next;
	g_model->next = (t_model *)model1;
	if (str[0])
		ft_putchar('\0');
	return (model1);
}
