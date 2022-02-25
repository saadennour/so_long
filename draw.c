/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:00:02 by sfarhan           #+#    #+#             */
/*   Updated: 2022/02/24 00:01:54 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <string.h>

int	shut(t_data *data)
{
	mlx_destroy_window (data->var.mlx, data->var.win);
	exit(0);
}

void	string(t_data *data)
{
	static int	g_f;
	char		*str;
	int			i;

	i = 0;
	i = g_f;
	str = ft_itoa (g_f);
	g_f++;
	mlx_string_put (data->var.mlx, data->var.win, 10, 10, BLACK, str);
	free (str);
}

int	complete(t_data *data, int i, int j)
{
	if (data->var.map[i][j] == 'P')
		mlx_put_image_to_window (data->var.mlx, data->var.win,
			data->player.relative, j * 80, i * 80);
	else if (data->var.map[i][j] == 'C')
		mlx_put_image_to_window (data->var.mlx, data->var.win,
			data->relative_gold, j * 80, i * 80);
	else if (data->var.map[i][j] == 'E')
	{
		mlx_put_image_to_window (data->var.mlx, data->var.win,
			data->relative_back, j * 80, i * 80);
		mlx_put_image_to_window (data->var.mlx, data->var.win,
			data->relative_boat, j * 80, i * 80);
	}
	else if (data->var.map[i][j] == 'H')
		mlx_put_image_to_window (data->var.mlx, data->var.win,
			data->relative_monster, j * 80, i * 80);
	return (0);
}

int	draw_map(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while ((data->var.map)[i])
	{
		j = 0;
		while ((data->var.map)[i][j])
		{
			if ((data->var.map)[i][j] == '1')
				mlx_put_image_to_window (data->var.mlx, data->var.win,
					data->relative_back, j * 80, i * 80);
			else if ((data->var.map)[i][j] != '1')
				mlx_put_image_to_window (data->var.mlx, data->var.win,
					data->relative_sand, j * 80, i * 80);
			complete(data, i, j);
			j++;
		}
		i++;
	}
	string(data);
	return (0);
}
