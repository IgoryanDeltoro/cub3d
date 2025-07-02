/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/01 19:51:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void initial_player(t_player *player)
{
    player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
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
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	initial_player(&game->player);
	initial_textures(game->textures);
	initial_ray_cast(game);
}
