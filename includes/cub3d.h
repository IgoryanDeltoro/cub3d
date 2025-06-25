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
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_img 
{
    void    *img;
    int     *data;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
} t_img;

typedef struct s_player 
{
    double  x;
    double  y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
} t_player;

typedef struct s_game 
{
    void        *mlx;
    void        *win;
    t_img       textures[4];   // NO, SO, WE, EA
    int         floor_color;
    int         ceiling_color;
    char        **map;
    int         map_width;
    int         map_height;
    t_player    player;
} t_game;

void    validate_imputs(int ac, char *str);
void    initial_game(t_game *game);
void	print_error(char *str);
void    exit_with_error(t_game *game, char *error);
void	init_mlx(t_game *game);

#endif