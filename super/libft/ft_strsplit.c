/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 03:26:12 by kupsyloc          #+#    #+#             */
/*   Updated: 2019/09/19 20:49:47 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_count(char *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static char		**free_ft_split(char **result, int i)
{
	while (i >= 0)
	{
		ft_strdel(&result[i]);
		i--;
	}
	free(result);
	result = NULL;
	return (result);
}

static char		**ft_make_split(char **result, char *str, char c, size_t j)
{
	size_t		i;
	size_t		start;
	size_t		x;

	i = 0;
	start = 0;
	x = 0;
	while (str[i] != '\0' && x < j)
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			result[x] = ft_strsub(str, start, i - start);
			if (result[x] == NULL)
				return (free_ft_split(result, x));
			x++;
		}
		else
			i++;
	}
	result[x] = NULL;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	size_t		i;

	if (!s)
		return (NULL);
	i = ft_sub_count((char*)s, c);
	result = NULL;
	if ((result = (char**)malloc((i + 1) * sizeof(char*))) == NULL)
		return (NULL);
	if (!result)
		return (NULL);
	result = ft_make_split(result, (char*)s, c, i);
	return (result);
}
