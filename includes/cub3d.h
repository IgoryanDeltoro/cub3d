/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:23 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:16:23 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "libft.h"
# include "error_message.h"
# include "../utils/minilibx-linux/mlx.h"
// # include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>


# define WIDTH 1900
# define HEIGHT 800
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define COLL_MARGIN 0.5

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# 	endif

typedef struct s_textures 
{
    void    *img;
    int     *data;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
} t_textures;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_game 
{
	int			fd;
	void		*mlx;
	void		*win;
	t_textures	textures[4];
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			map_width;
	int			map_height;
	t_player	player;
}				t_game;

void	initial_game(t_game *game);
void	print_error(char *str);
int		exit_with_error(t_game *game, char *error);
void	init_mlx(t_game *game);
int     close_game(t_game *game);
int     handle_button_listeners(int keycode, t_game *game);
void    run_game(t_game *game);
void    move_forward(t_game *game);
void    move_backward(t_game *game);
void    move_left(t_game *game);
void    move_right(t_game *game);

// MAIN FUNCTIONS
int     parse_cub_file(char *file, t_game *game);
int    render_map(void *game);


// UTILS
void    error_exit(const char *msg);
char    *get_next_line(int fd);
int     rgb_to_int(int r, int g, int b);

/////////////  get_next_line ///////////
char	*get_next_line(int fd);
ssize_t	ft_str_chr(char *str);
int		read_map(t_game *data);
void	validate_imputs(t_game *game, int ac, char *str);

////////// parse /////////////
int		pars_check_valid_collor(char *str);
int		pars_init_collor(t_game *game, char **collor);
int		pars_collor(t_game *game, char *temp, int *col, int n);
int		pars_check_comma(char *str);

char	*utils_str_join(char *str1, char *str2);
char	*pars_create_map_string(t_game *game, char *map_str, char *temp);
int		pars_check_item(char **map, int i, int j, char ch);
int		pars_map_1(t_game *game, int i, int *n);
int		pars_map(t_game *game, char *map_str);

int		pars_check_line(char *s);
int		pars_no_so_we_ea(t_game *game, char **texture, char **str);
int		pars_texture_1(t_game *game, char **texture);
int		pars_texture(t_game *game, char *temp, int *count, int n);

////////////// init //////////////

void	free_2d(char **str);
int		free_game(t_game *game);

#endif
