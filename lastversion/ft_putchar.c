/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:23:53 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:45:00 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_putchar(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	ft_putchar_fd(s, 1);
}
