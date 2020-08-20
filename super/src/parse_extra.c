/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:47:33 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:47:34 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
