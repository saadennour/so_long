/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:58:38 by sfarhan           #+#    #+#             */
/*   Updated: 2022/02/25 21:38:10 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_help(t_data *data, int i, int j, int collect)
{
	if ((data->var.map)[i][j] == 'P'
		&& (data->var.map)[i - 1][j] == 'C')
			(data->var.map)[i - 1][j] = '0';
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i - 1][j] == 'H')
	{
		ft_putstr ("D3IIIIF\n");
		exit (0);
	}
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i - 1][j] == 'E' && collect == 0)
	{
		if (collect == 0)
			ft_win(data, i, j);
		return (1);
	}
	return (0);
}

int	down_help(t_data *data, int i, int j, int collect)
{
	if ((data->var.map)[i][j] == 'P'
		&& (data->var.map)[i + 1][j] == 'C')
			(data->var.map)[i + 1][j] = '0';
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i + 1][j] == 'H')
	{
		ft_putstr ("D3IIIIF\n");
		exit (0);
	}
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i + 1][j] == 'E')
	{
		if (collect == 0)
			ft_win(data, i, j);
		return (1);
	}
	return (0);
}

int	right_help(t_data *data, int i, int j, int collect)
{
	if ((data->var.map)[i][j] == 'P'
		&& (data->var.map)[i][j + 1] == 'C')
			(data->var.map)[i][j + 1] = '0';
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i][j + 1] == 'H')
	{
		ft_putstr ("D3IIIIF\n");
		exit (0);
	}
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i][j + 1] == 'E' && collect == 0)
	{
		if (collect == 0)
			ft_win(data, i, j);
		return (1);
	}
	return (0);
}

int	left_help(t_data *data, int i, int j, int collect)
{
	if ((data->var.map)[i][j] == 'P'
		&& (data->var.map)[i][j - 1] == 'C')
			(data->var.map)[i][j - 1] = '0';
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i][j - 1] == 'E' && collect == 0)
	{
		if (collect == 0)
			ft_win(data, i, j);
		return (1);
	}
	else if ((data->var.map)[i][j] == 'P'
			&& (data->var.map)[i][j - 1] == 'H')
	{
		ft_putstr ("D3IIIIF\n");
		exit (0);
	}
	return (0);
}
