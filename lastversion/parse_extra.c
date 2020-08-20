/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:52:31 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 14:03:14 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		remove_struct(void)
{
	t_model		*model1;
	t_model		*buffer;

	model1 = g_model->next;
	free(g_model);
	while (model1->value)
	{
		buffer = model1->next;
		free(model1->str);
		free(model1);
		model1 = buffer;
		if (buffer == NULL)
			return ;
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
