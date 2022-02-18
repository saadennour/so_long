#include "so_long.h"
#include <fcntl.h>

int shut (t_data *data)
{
    mlx_destroy_window (data->var.mlx, data->var.win);
    exit(0);
}

int draw_map(t_data *data)
{
    int i = 0;
    int j = 0;

    while ((data->var.map)[i])
    {
        j = 0;
        while ((data->var.map)[i][j])
        {
            if ((data->var.map)[i][j] == '1' || (data->var.map)[i][j] == 'E')
                mlx_put_image_to_window (data->var.mlx, data->var.win, data->relative_back, j* 80, i * 80);
            else if ((data->var.map)[i][j] != '1')
                mlx_put_image_to_window (data->var.mlx, data->var.win, data->relative_sand, j * 80, i * 80);
            if (data->var.map[i][j] == 'P')
                mlx_put_image_to_window (data->var.mlx, data->var.win, data->player.relative, j * 80, i * 80);
            if (data->var.map[i][j] == 'C')
                mlx_put_image_to_window (data->var.mlx, data->var.win, data->relative_gold, j * 80, i * 80);
            if (data->var.map[i][j] == 'E')
                mlx_put_image_to_window (data->var.mlx, data->var.win, data->relative_boat, j * 80, i * 80);
            j++;
        }
        i++;
    }
    return (0);
}
