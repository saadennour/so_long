# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include  <mlx.h>
#include "get_next_line.h"


#define WHITE   0x00FFFFFF
#define RED     0x00FF0000
#define GREEN   0x0000FF00
#define BLUE    0x000000FF
#define BLACK   0x00000000
#define YELLOW  0x00FFFF00
#define PURPLE  0x00FF00FF

// typedef struct s_data {
//     void *img;
//     char *addr;
//     int bpp;
//     int line;
//     int endian;
// }              t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
    int     x;
    int     y;
    char    **map;
    int     line;
    int     lenght;
}				t_vars;

typedef struct t_player {
    void    *relative;
    int     x;
    int     y;
    int     counter;
}               t_player;

typedef struct t_data {
    t_vars      var;
    t_player    player;
    void        *relative_back;
    void        *relative_sand;
    void        *relative_gold;
    void        *relative_boat;
}               t_data;

char	**ft_split(char const *s, char c);
int     check_map(char **s, int line, int lenght);
char    **size(int fd, int line, int lenght);
int     draw_map(t_data *data);
int     init_vars(t_data *data , char *mapname);
int	    key_hook(int keycode, t_data *data);
int     shut (t_data *data);

# endif