
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 100
# endif

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


void	read_map(t_game *data, char **av);
char	*utils_str_join(char *str1, char *str2);

#endif
