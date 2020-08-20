/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:44:12 by aghar             #+#    #+#             */
/*   Updated: 2020/08/20 21:44:13 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_putchar(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	ft_putchar_fd(s, 1);
}
