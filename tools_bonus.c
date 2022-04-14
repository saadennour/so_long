/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:39:49 by sfarhan           #+#    #+#             */
/*   Updated: 2022/02/27 03:18:58 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	ft_win(t_data *data, int i, int j)
{
	(data->var.map)[i][j] = '0';
	ft_putstr ("YOUU WIIN !!");
	exit (0);
}

int	counter(t_data *data)
{
	int	i;
	int	j;

	data->player.counter = 0;
	i = 0;
	while ((data->var.map)[i])
	{
		j = 0;
		while ((data->var.map)[i][j])
		{
			if ((data->var.map)[i][j] == 'C')
				data->player.counter++;
			j++;
		}
		i++;
	}
	return (data->player.counter);
}

int	ft_ber(char *s)
{
	int	i;
	int	diff;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			diff = ft_strncmp(&s[i], ".ber", 4);
		i++;
	}
	return (diff);
}

int	strange(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != '1' && s[i][j] != '0' && s[i][j] != 'C'
				&& s[i][j] != 'E' && s[i][j] != 'P' && s[i][j] != '\n'
				&& s[i][j] != 'H')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	gold_hunt(t_data *data)
{
	int	w;
	int	h;

	data->var.mlx = mlx_init();
	data->var.win = mlx_new_window (data->var.mlx,
			data->var.x * data->var.lenght,
			data->var.y * data->var.line, "GOLD HUNT");
	data->relative_back = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/water2.xpm", &w, &h);
	data->relative_sand = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/sand.xpm", &w, &h);
	data->player.relative = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/pirate2.xpm", &w, &h);
	data->relative_gold = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/gold.xpm", &w, &h);
	data->relative_boat = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/boat2.xpm", &w, &h);
	data->relative_monster = mlx_xpm_file_to_image
		(data->var.mlx, "./pics/spike.xpm", &w, &h);
}
