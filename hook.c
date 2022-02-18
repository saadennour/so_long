#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int mouse_hook (int button, int x, int y, t_vars *vars)
{
    int time = 0;

    if (button == 1)
        printf ("u clicked on the left button !\n");
    else if (button == 2)
        printf ("u clicked on the right button !\n");
    else if (button == 3)
        printf ("u clicked on the middle button !\n");
    else if (button == 4)
        printf ("u scrolled up !\n");
    else if (button == 5)
        printf ("u scrolled down !\n");
    printf ("ur position is : %d and %d\n", x,y);
    return (0);
}


// int	main()
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//     //mlx_key_hook(vars.win, key_hook, &vars);
//     //mlx_mouse_hook(vars.win, mouse_hook, &vars);
//     //mlx_hook (vars.win, 17, 0, ft_exit, &vars);
//     mlx_hook (vars.win, 2, 1L<<0, key_hook, &vars);
// 	mlx_loop(vars.mlx);
//     // W = 13;
//     // a = 0;
//     // s = 1;
//     // d = 2;
// }