/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:41:34 by sfarhan           #+#    #+#             */
/*   Updated: 2022/08/29 03:56:21 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	uno(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '1')
			count++;
		else
			return (0);
		i++;
	}
	return (count);
}

int	segundo(char *s, int count)
{
	if (s[0] == '1' && s[count - 1] == '1')
		return (1);
	return (0);
}

int	player(char *s)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (s[i])
	{
		if (s[i] == 'P')
			p++;
		i++;
	}
	return (p);
}

int	collectible(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

int	out(char *s)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (s[i])
	{
		if (s[i] == 'E')
			e++;
		i++;
	}
	return (e);
}
