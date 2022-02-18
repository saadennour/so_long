#include "so_long.h"

int	key_hook(int keycode, t_vars *var)
{
    int i = 10;
    int j = 10;

    if (keycode == 53)
        mlx_destroy_window (var->mlx, var->win);
    // vars->win = mlx_new_window (vars->mlx, 1080, 720, "try");
    if (keycode == 13)
        mlx_put_image_to_window (var->mlx, var->win, var->img, var->x, var->y - j);
    else if (keycode == 0)
        mlx_put_image_to_window (var->mlx, var->win, var->img, var->x - i, var->y);
    if (keycode == 1)
        mlx_put_image_to_window (var->mlx, var->win, var->img, var->x, var->y + j);
    if (keycode == 2)
        mlx_put_image_to_window (var->mlx, var->win, var->img, var->x + i, var->y);
	printf("Hello from key_hook %d!\n", keycode);
	return (0);
}

// int main()
// {
//     t_vars  var;
//     char    *relative_path = "./pirate2.xpm";
//     int     img_width;
//     int     img_height;
//     var.x = 20;
//     var.y = 20;

//     var.mlx = mlx_init();
//     var.win = mlx_new_window (var.mlx, 720, 720, "image");
//     var.img = mlx_xpm_file_to_image (var.mlx, relative_path, &img_width, &img_height);
//     // if (img == NULL)
//     //     printf ("error");
//     mlx_put_image_to_window (var.mlx, var.win, var.img, var.x, var.y);
//     mlx_hook (var.win, 2, 1L<<0, key_hook, &var);
//     mlx_loop(var.mlx);
// }