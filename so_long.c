#include <stdio.h>
#include <stdlib.h>
#include  <mlx.h>


#define WHITE   0x00FFFFFF
#define RED     0x00FF0000
#define GREEN   0x0000FF00
#define BLUE    0x000000FF
#define BLACK   0x00000000
#define YELLOW  0x00FFFF00
#define PURPLE  0x00FF00FF

typedef struct s_data {
    void *img;
    char *addr;
    int bpp;
    int line;
    int endian;
}              t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    square (t_data img, int i, int j, int max)
{
    int x = 0;
    int y = 0;

    while (x <= max)
    {
        my_mlx_pixel_put(&img, i+x, j, RED);
        x++;
    }
    while (y <= max)
    {
        my_mlx_pixel_put(&img, i, j+y, RED);
        y++;
    }
    x = 0;
    while (x <= max)
    {
        my_mlx_pixel_put(&img, i+x, j+y, RED);
        x++;
    }
    y = 0;
    while (y <= max)
    {
        my_mlx_pixel_put(&img, i+x, j+y, RED);
        y++;
    }
}

void    triangle (t_data img, int i, int j, int max)
{
    int x = 0;
    int y = 0;

    while (x <= max)
    {
        my_mlx_pixel_put(&img, i+x, j+x, WHITE);
        x++;
    }
    x = 0;
    while (y <= max)
    {
        my_mlx_pixel_put(&img, i-y, j+y, WHITE);
        y++;
    }
    while (x <= 2*max)
    {
        my_mlx_pixel_put(&img, i+y-x, j+y, WHITE);
        x++;
    }
}

int main()
{
    void    *mlx_ptr;
    void    *window;
    t_data    img;

    int i = 1;
    int j = 1;

    mlx_ptr = mlx_init();
    window = mlx_new_window (mlx_ptr, 1920, 1080, "test");
    img.img = mlx_new_image (mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
    // while (i < 1920)
    // {
    //     j = 1;
    //     while (j < 1080)
    //     {
    //         my_mlx_pixel_put (&img, i, j, RED);
    //         j++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while (i < 1920)
    // {
    //     j = 100;
    //     while (j < 200)
    //     {
    //         my_mlx_pixel_put (&img, i, j, GREEN);
    //         j++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while (i < 1920)
    // {
    //     j = 200;
    //     while (j < 300)
    //     {
    //         my_mlx_pixel_put (&img, i, j, BLUE);
    //         j++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while (i < 1920)
    // {
    //     j = 300;
    //     while (j < 400)
    //     {
    //         my_mlx_pixel_put (&img, i, j, PURPLE);
    //         j++;
    //     }
    //     i++;
    // }
    // i = 0;
    // while (i < 1920)
    // {
    //     j = 400;
    //     while (j < 500)
    //     {
    //         my_mlx_pixel_put (&img, i, j, YELLOW);
    //         j++;
    //     }
    //     i++;
    //}
    square (img, 50, 50, 500);
    // triangle (img, 720, 400, 500);
    mlx_put_image_to_window (mlx_ptr, window, img.img, 0, 0);
    mlx_loop(mlx_ptr);
}
