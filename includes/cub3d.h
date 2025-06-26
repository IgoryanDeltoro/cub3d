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

#include <fcntl.h>
# include "libft.h"
# include "error_message.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100

# endif

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct	s_player 
{
	double  x;
	double  y;
	double  dir_x;
	double  dir_y;
	double  plane_x;
	double  plane_y;
} t_player;

typedef struct	s_game
{
	int			fd;
	void		*mlx;
	void		*win;
	t_img		textures[4];
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

char	*get_next_line(int fd);

void	validate_imputs(t_game *game, int ac, char *str);
void	initial_game(t_game *game);
void	print_error(char *str);
void	exit_with_error(t_game *game, char *error);
void	init_mlx(t_game *game);
int		read_map(t_game *data);
void	free_2d(char **str);
void    free_game(t_game *game);

#endif
