/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:15:31 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/08/16 02:50:57 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	s;

	s = (unsigned char)c;
	write(fd, &s, sizeof(c));
}
