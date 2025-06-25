#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>

typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				**map;
	int					map_width;
	int					map_height;
	int					def_size_img;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
}						t_game;

#endif