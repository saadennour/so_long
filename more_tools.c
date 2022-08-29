/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:35:25 by sfarhan           #+#    #+#             */
/*   Updated: 2022/08/29 03:59:12 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_lenght(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i][j])
		j++;
	return (j);
}

static int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nb)
{
	unsigned int	a;

	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	a = nb;
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
	{
		a += '0';
		ft_putchar(a);
	}
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		i += 1;
	}
	return (i);
}
