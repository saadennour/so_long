#include "so_long.h"
#include <fcntl.h>


int move_up (t_data *data)
{
    int i = 0;
    int j = 0;
    char swap;

    while ((data->var.map)[i])
    {
        j = 0;
        while ((data->var.map)[i][j])
        {
            if ((data->var.map)[i][j] == 'P' && (data->var.map)[i - 1][j] != '1')
            {
                if ((data->var.map)[i][j] == 'P' && (data->var.map)[i - 1][j] == 'C')
                    (data->var.map)[i - 1][j] = '0';
                swap = (data->var.map)[i - 1][j];
                (data->var.map)[i - 1][j] = (data->var.map)[i][j];
                (data->var.map)[i][j] = swap;
                draw_map(data);
                data->player.counter++;
                return (data->player.counter);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int move_down (t_data *data)
{
    int i = 0;
    int j = 0;
    char swap;

    while ((data->var.map)[i])
    {
        j = 0;
        while ((data->var.map)[i][j])
        {
            if ((data->var.map)[i][j] == 'P' && (data->var.map)[i + 1][j] != '1')
            {
                if ((data->var.map)[i][j] == 'P' && (data->var.map)[i + 1][j] == 'C')
                    (data->var.map)[i + 1][j] = '0';
                swap = (data->var.map)[i + 1][j];
                (data->var.map)[i + 1][j] = (data->var.map)[i][j];
                (data->var.map)[i][j] = swap;
                draw_map(data);
                data->player.counter++;
                return (data->player.counter);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int move_right (t_data *data)
{
    int i = 0;
    int j = 0;
    char swap;

    while ((data->var.map)[i])
    {
        j = 0;
        while ((data->var.map)[i][j])
        {
            if ((data->var.map)[i][j] == 'P' && (data->var.map)[i][j + 1] != '1')
            {
                if ((data->var.map)[i][j] == 'P' && (data->var.map)[i][j + 1] == 'C')
                    (data->var.map)[i][j + 1] = '0';
                swap = (data->var.map)[i][j + 1];
                (data->var.map)[i][j + 1] = (data->var.map)[i][j];
                (data->var.map)[i][j] = swap;
                draw_map(data);
                data->player.counter++;
                return (data->player.counter);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int move_left (t_data *data)
{
    int i = 0;
    int j = 0;
    char swap;

    while ((data->var.map)[i])
    {
        j = 0;
        while ((data->var.map)[i][j])
        {
            if ((data->var.map)[i][j] == 'P' && (data->var.map)[i][j - 1] != '1')
            {
                if ((data->var.map)[i][j] == 'P' && (data->var.map)[i][j - 1] == 'C')
                    (data->var.map)[i][j - 1] = '0';
                swap = (data->var.map)[i][j - 1];
                (data->var.map)[i][j - 1] = (data->var.map)[i][j];
                (data->var.map)[i][j] = swap;
                draw_map(data);
                data->player.counter++;
                return (data->player.counter);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int	key_hook(int keycode, t_data *data)
{
    int i = 0;
    int j = 0;
    char swap;
    data->player.counter = 0;

    if (keycode == 53)
    {
        mlx_destroy_window (data->var.mlx, data->var.win);
        exit(0);
    }
    else if (keycode == 0)
        move_left(data);
    else if (keycode == 2)
        move_right(data);
    else if (keycode == 1)
        move_down(data);
    else if (keycode == 13)
        move_up(data);
	return (0);
}