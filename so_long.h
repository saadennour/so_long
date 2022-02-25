/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:00:24 by sfarhan           #+#    #+#             */
/*   Updated: 2022/02/25 21:45:10 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include  <mlx.h>
# include "get_next_line.h"

# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define BLACK	0x00000000
# define YELLOW	0x00FFFF00
# define PURPLE	0x00FF00FF

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	char	**map;
	int		line;
	int		lenght;
}				t_vars;

typedef struct t_player {
	void	*relative;
	int		x;
	int		y;
	int		counter;
}				t_player;

typedef struct t_data {
	t_vars		var;
	t_player	player;
	void		*relative_back;
	void		*relative_sand;
	void		*relative_gold;
	void		*relative_boat;
	void		*relative_monster;
}				t_data;

int		counter(t_data *data);
char	**ft_split(char const *s, char c);
int		check_map(char **s, int line, int lenght);
char	**size(int fd, int lenght);
int		draw_map(t_data *data);
int		init_vars(t_data *data, char *mapname);
int		key_hook(int keycode, t_data *data);
int		shut(t_data *data);
void	ft_win(t_data *data, int i, int j);
int		ft_ber(char *s);
int		strange(char **s);
int		uno(char *s);
int		segundo(char *s, int count);
int		player(char *s);
int		collectible(char *s);
int		out(char *s);
int		complete(t_data *data, int i, int j);
int		up_help(t_data *data, int i, int j, int collect);
int		down_help(t_data *data, int i, int j, int collect);
int		right_help(t_data *data, int i, int j, int collect);
int		left_help(t_data *data, int i, int j, int collect);
int		ft_lenght(char **s);
int		ft_lines(char **s);
void	gold_hunt(t_data *data);
int		ft_putstr(char *str);
#endif
