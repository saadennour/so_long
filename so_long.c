/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:00:47 by sfarhan           #+#    #+#             */
/*   Updated: 2022/08/29 03:59:32 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	buno(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			count++;
		else
			return (0);
		i++;
	}
	return (count);
}

char	**size(int fd)
{
	int		i;
	char	**s;
	char	*ob;
	char	*line;

	i = 0;
	ob = NULL;
	line = get_next_line(fd, 10000000);
	if (line == NULL)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	while (line != NULL)
	{
		ob = ft_strjoin(ob, line);
		line = get_next_line(fd, 1);
	}
	s = ft_splito(ob, '\n');
	return (s);
}

int	check_map(char **s, int line, int lenght)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	lenght = uno(s[0]);
	while (++i < line - 1 && lenght != 0)
	{
		if (segundo(s[i], lenght) == 0)
			return (0);
		p += player(s[i]);
		c += collectible(s[i]);
		e += out(s[i]);
	}
	lenght = buno(s[line - 1]);
	if (lenght == 0 || strange(s) == 0)
		return (0);
	if (p == 1 && c >= 1 && e >= 1)
		return (1);
	return (0);
}

int	init_vars(t_data *data, char *mapname)
{
	int	fd;

	fd = open(mapname, O_RDWR);
	data->var.lenght = 0;
	data->var.line = 0;
	data->var.x = 80;
	data->var.y = 80;
	data->var.map = size(fd);
	data->var.line = ft_lines(data->var.map);
	data->var.lenght = ft_lenght(data->var.map);
	if (check_map(data->var.map, data->var.line, data->var.lenght) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	gold_hunt(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || ft_ber(av[1]) != 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (init_vars(&data, av[1]) == 0)
		return (0);
	draw_map(&data);
	mlx_hook(data.var.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.var.win, 17, 1L << 0, shut, &data);
	mlx_loop(data.var.mlx);
}
