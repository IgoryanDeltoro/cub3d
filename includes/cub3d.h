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

# include "libft.h"
# include "error_message.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1900
# define HEIGHT 800
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define COLL_MARGIN 0.5
# define MAP_H_SIZE 300
# define MAP_W_SIZE 300
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_textures
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
}			t_textures;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_ray_cast
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		tex_index;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	int		side;
	int		tex_x;
}			t_ray_cast;

typedef struct s_game
{
	int			fd;
	void		*mlx;
	void		*win;
	t_textures	textures[4];
	int			floor_color;
	int			ceiling_color;
	t_img		screen_buffer;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			map_width;
	int			map_height;
	t_player	player;
	t_ray_cast	ray_c;
}				t_game;

void	initial_game(t_game *game);
void	print_error(char *str);
int		exit_with_error(t_game *game, char *error);
void	init_mlx(t_game *game);
int		close_game(t_game *game);
int		handle_button_listeners(int keycode, t_game *game);
bool	run_game(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		render_map(void *game);
char	*get_next_line(int fd);
int		rgb_to_int(int a, int b, int c);
char	*get_next_line(int fd);
ssize_t	ft_str_chr(char *str);
int		read_map(t_game *data);
void	validate_imputs(t_game *game, int ac, char *str);
int		pars_check_valid_color(char *str);
int		pars_init_color(t_game *game, char **color);
int		pars_color(t_game *game, char *temp, int *col, int n);
int		pars_check_comma(char *str);
char	*utils_str_join(char *str1, char *str2);
char	*pars_create_map_string(t_game *game, char **map_str, char *temp);
int		pars_check_item(char **map, int i, int j, bool val);
int		pars_map_1(t_game *game, int i, int *n);
int		pars_map(t_game *game, char *map_str);
int		pars_check_line(char *s);
int		pars_no_so_we_ea(t_game *game, char **texture, char **str);
int		pars_texture_1(t_game *game, char **texture);
int		pars_texture(t_game *game, char *temp, int *count, int n);
void	free_2d(char **str);
int		free_game(t_game *game);
void	calculate_perp_wall_dist(t_game *game);
void	calculate_dist(t_game *game);
void	calculate_ray_dir(t_game *game, int x);
void	calculate_wall_slice_height(t_game *game);
void	select_texture(t_game *game);
void	put_pixel_to_buffer(t_img *buffer, int x, int y, int color);
void	take_player_position(t_game *game);

#endif
