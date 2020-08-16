/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:00:54 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 02:44:49 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		parseMain(const char *str, va_list arg_list)
{
	int			ft_printf;

	model = pushModel(str, NULL, 1);
	parseSec(str, arg_list);
	debugStruct(model);
	ft_printf = print_result();
	removeStruct();
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

int		parseSec(const char *str, va_list arg_list)
{
	int len[2];

	len[0] = 0;
	len[1] = 0;
	while (str[(len[1] + len[0])])
	{
		if (str[len[1] + len[0]] == '%')
		{
			pushModel(ft_strsub(str, len[0], len[1]), model, 02);
			len[1] += parsePros((char *)str + (len[0] + len[1]), arg_list);
			len[0] += len[1];
			len[1] = 0;
		}
		else
			len[1]++;
	}
	pushModel(ft_strsub(str, len[0], len[1]), model, 022);
}

int		parsePros(char *str, va_list arg_list)
{
	int			len;
	t_info		test;

	test = info_init();
	len = check_manager(str, &test);
	pusher_manager(&test, arg_list);
	return (len);
}

t_model	*pushModel(const char *str, t_model *model, int isNew)
{
	t_model		*model1;

	model1 = (t_model *)malloc(sizeof(t_model));
	model1->value = isNew;
	model1->str = (char *)str;
	model1->next = NULL;
	if (isNew == 1)
		return (model1);
	while (model->next != NULL)
		model = (t_model *)model->next;
	model->next = (t_model *)model1;
	return (model1);
}

void		debugStruct(void)
{
	int			i;
	t_model		*model1;

	i = 0;
	model1 = model;
	while (model1)
	{
		if (model1->next == NULL)
			break ;
		model1 = model1->next;
		i++;
	}
	model1 = model;
	model1 = model1->next;
	while (model1)
	{
		if (model1->next == NULL)
			break ;
	model1 = (t_model *)model1->next;
	}
}

void		removeStruct(void)
{
	t_model		*model1;
	t_model		*buffer;

	model1 = model;
	model1 = model1->next;
	free(model);
	while (model1->value)
	{
		free(model1->str);
		buffer = model1->next;
		free(model1);
		model1 = buffer;
		if (buffer->next == NULL)
		{
			free(model1->str);
			buffer = model1->next;
			free(model1);
			model1 = buffer;
			break ;
		}
	}
}
