/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:00:43 by sfarhan           #+#    #+#             */
/*   Updated: 2022/02/22 21:10:08 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_data *data, int collect)
{
	int		i;
	int		j;
	char	swap;

	i = -1;
	while ((data->var.map)[++i])
	{
		j = -1;
		while ((data->var.map)[i][++j])
		{
			if ((data->var.map)[i][j] == 'P'
				&& (data->var.map)[i - 1][j] != '1')
			{
				if (up_help(data, i, j, collect) == 0)
				{
					swap = (data->var.map)[i - 1][j];
					(data->var.map)[i - 1][j] = (data->var.map)[i][j];
					(data->var.map)[i][j] = swap;
					draw_map(data);
					return (0);
				}
			}
		}
	}
	return (0);
}

static int	move_down(t_data *data, int collect)
{
	int		i;
	int		j;
	char	swap;

	i = -1;
	while ((data->var.map)[++i])
	{
		j = -1;
		while ((data->var.map)[i][++j])
		{
			if ((data->var.map)[i][j] == 'P'
				&& (data->var.map)[i + 1][j] != '1')
			{
				if (down_help(data, i, j, collect) == 0)
				{
					swap = (data->var.map)[i + 1][j];
					(data->var.map)[i + 1][j] = (data->var.map)[i][j];
					(data->var.map)[i][j] = swap;
					draw_map(data);
					return (0);
				}
			}
		}
	}
	return (0);
}

static int	move_right(t_data *data, int collect)
{
	int		i;
	int		j;
	char	swap;

	i = -1;
	while ((data->var.map)[++i])
	{
		j = -1;
		while ((data->var.map)[i][++j])
		{
			if ((data->var.map)[i][j] == 'P'
				&& (data->var.map)[i][j + 1] != '1')
			{
				if (right_help(data, i, j, collect) == 0)
				{
					swap = (data->var.map)[i][j + 1];
					(data->var.map)[i][j + 1] = (data->var.map)[i][j];
					(data->var.map)[i][j] = swap;
					draw_map(data);
					return (0);
				}
			}
		}
	}
	return (0);
}

static int	move_left(t_data *data, int collect)
{
	int		i;
	int		j;
	char	swap;

	i = -1;
	while ((data->var.map)[++i])
	{
		j = -1;
		while ((data->var.map)[i][++j])
		{
			if ((data->var.map)[i][j] == 'P'
				&& (data->var.map)[i][j - 1] != '1')
			{
				if (left_help(data, i, j, collect) == 0)
				{
					swap = (data->var.map)[i][j - 1];
					(data->var.map)[i][j - 1] = (data->var.map)[i][j];
					(data->var.map)[i][j] = swap;
					draw_map(data);
					return (0);
				}
			}
		}
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int		collect;

	collect = counter (data);
	if (keycode == 53)
	{
		mlx_destroy_window (data->var.mlx, data->var.win);
		exit(0);
	}
	else if (keycode == 0)
	{
		data->player.relative = mlx_xpm_file_to_image
			(data->var.mlx, "./pics/pirate.xpm", &data->w, &data->h);
		collect = move_left(data, collect);
	}
	else if (keycode == 2)
	{
		data->player.relative = mlx_xpm_file_to_image
			(data->var.mlx, "./pics/pirate2.xpm", &data->w, &data->h);
		collect = move_right(data, collect);
	}
	else if (keycode == 1)
		collect = move_down(data, collect);
	else if (keycode == 13)
		collect = move_up(data, collect);
	return (0);
}
