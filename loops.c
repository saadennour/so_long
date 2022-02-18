#include "so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *var)
{
    if (keycode == 53)
        mlx_destroy_window (var->mlx, var->win);
    // vars->win = mlx_new_window (vars->mlx, 1080, 720, "try");
    if (keycode == 13)
        mlx_put_image_to_window (var->mlx, var->win, var->img, 0, 0);
	printf("Hello from key_hook %d!\n", keycode);
	return (0);
}

int render_next_frame(t_vars *var)
{
    char    *relative_path = "./pirate2.xpm";
    int     img_width;
    int     img_height;
    int x = 0;
    int y = 10;

    var->img = mlx_xpm_file_to_image (var->mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window (var->mlx, var->win, var->img, x, y);
    mlx_hook (var->win, 2, 1L<<0, key_hook, &var);
    mlx_loop(var->mlx);
}


int main()
{
    t_vars  var;

    var.mlx = mlx_init();
    var.win = mlx_new_window (var.mlx, 1080, 720, "FRAME");
    mlx_loop_hook (var.mlx, render_next_frame, &var);
    mlx_loop(var.mlx);
}