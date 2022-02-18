#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

static int uno (char *s)
{
    int i = 0;
    int count = 0;

    while (s[i] != '\n')
    {
        if (s[i] == '1')
            count++;
        else
            return (0);
        i++;
    }
    return (count);
}

static int buno (char *s)
{
    int i = 0;
    int count = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '1')
            count++;
        else
            return (0);
        i++;
    }
    return (count);
}

int segundo (char *s, int count)
{
    if (s[0] == '1' && s[count - 1] == '1')
        return (1);
    return (0);
}

int player (char *s)
{
    int i = 0;
    int p = 0;

    while (s[i] != '\n')
    {
        if (s[i] == 'P')
            p++;
        i++;
    }
    return (p);
}

int collectible (char *s)
{
    int i;
    int c = 0;

    i = 0;
    while (s[i] != '\n')
    {
        if (s[i] == 'C')
            c++;
        i++;
    }
    return (c);
}

int out (char *s)
{
    int i;
    int e;

    i = 0;
    e = 0;
    while (s[i] != '\n')
    {
        if (s[i] == 'E')
            e++;
        i++;
    }
    return (e);
}

char **size(int fd, int line, int lenght)
{
    int i = 1;
    char **s;
    char *ob;
    
    ob = get_next_line(fd, 13);
    lenght = ft_strlen (ob);
    s = malloc(sizeof(char *) * lenght);
    s[0] = ob;
    while ((s[i] = get_next_line(fd, 13)))
    {
        s[i][lenght] = '\0';
        i++;
        line++;
    }
    s[i] = 0;
    printf ("%d lines and %d lenght\n", line, lenght);
    return (s);
}

int check_map(char **s, int line, int lenght)
{
    int i = 1;
    int count = 0;
    int p = 0;
    int c = 0;
    int e = 0;
    int seg = 0;

    lenght = uno(s[0]);
    if (lenght == 0)
        return (0);
    while (i < line - 1)
    {
        seg = segundo(s[i], lenght);
        if (seg == 0)
            return (0);
        p += player(s[i]);
        c += collectible(s[i]);
        e += out(s[i]);
        i++;
    }
    lenght = buno(s[line - 1]);
    if (lenght == 0)
        return (0);
    if (p == 1 && c >= 1 && e >= 1)
        return (1);
    return (0);
}

int ft_lines (char **s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

int ft_lenght (char **s)
{
    int i = 0;
    int j = 0;

    while (s[i][j] != '\n')
        j++;
    return (j);
}

int init_vars(t_data *data, char *mapname)
{
    int fd;
    int w;
    int h;

    fd = open(mapname, O_RDWR);
    data->var.lenght = 0;
    data->var.line = 0;
    data->var.x = 80;
    data->var.y = 80;

    data->var.map = size(fd, data->var.line, data->var.lenght);
    data->var.line = ft_lines(data->var.map);
    data->var.lenght = ft_lenght (data->var.map);
    if (check_map(data->var.map, data->var.line, data->var.lenght) == 0)
    {
        printf ("Error\n");
        return (0);
    }
    data->var.mlx = mlx_init();
    data->var.win = mlx_new_window (data->var.mlx, data->var.x * data->var.lenght, data->var.y * data->var.line, "GOLD HUNT");
    data->relative_back = mlx_xpm_file_to_image (data->var.mlx, "./water2.xpm", &w, &h);
    data->relative_sand = mlx_xpm_file_to_image (data->var.mlx, "./grass.xpm", &w, &h);
    data->player.relative = mlx_xpm_file_to_image (data->var.mlx, "./pirate5.xpm", &w, &h);
    data->relative_gold = mlx_xpm_file_to_image (data->var.mlx, "./gold.xpm", &w, &h);
    data->relative_boat = mlx_xpm_file_to_image (data->var.mlx, "./boat2.xpm", &w, &h);
    return (1);
}

int main(int ac , char **av)
{
	int fd;
    int nbr = 0;
    char **s;
    t_data  data;
    
    if (init_vars(&data, av[1]) == 0)
        return (0);
    
    draw_map(&data);
    mlx_hook (data.var.win, 2, 1L<<0, key_hook, &data);
    mlx_hook (data.var.win, 17, 1L<<0, shut, &data);
    //system ("Leaks a.out");
    mlx_loop(data.var.mlx);
}