/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/03 14:05:16 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void initial_player(t_game *game)
{
	game->player.dir_x = -1;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0.66;
    game->player.x = 0;
	game->player.y = 0;
}

void initial_textures(t_textures *textures)
{
    textures->img = NULL;
	textures->data = 0;
	textures->width = 0;
	textures->height = 0;
	textures->bpp = 0;
	textures->line_len = 0;
	textures->endian = 0;
}

void initial_ray_cast(t_game *game)
{
	game->ray_c.ray_dir_x = 0;
	game->ray_c.ray_dir_y = 0;
	game->ray_c.delta_dist_x = 0;
	game->ray_c.delta_dist_y = 0;
	game->ray_c.side_dist_x = 0;
	game->ray_c.side_dist_y = 0;
	game->ray_c.perp_wall_dist = 0;
	// game->ray_c.wall_x = 0;
	game->ray_c.map_x = 0;
	game->ray_c.map_y = 0;
	game->ray_c.tex_index = 0;
	game->ray_c.line_height = 0;
	game->ray_c.draw_start = 0;
	game->ray_c.draw_end = 0;
	game->ray_c.step_x = 0;
	game->ray_c.step_y = 0;
	game->ray_c.side = 0;
	game->ray_c.tex_x = 0;
}

void	initial_game(t_game *game)
{
	game->no = NULL;
	game->ea = NULL;
	game->so = NULL;
	game->we = NULL;
	game->fd = -1;
	game->ceiling_color = -1;
	game->floor_color = -1;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	initial_player(game);
	initial_textures(game->textures);
	initial_ray_cast(game);
}

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}
