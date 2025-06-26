/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/26 13:21:54 by ibondarc         ###   ########.fr       */
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
void initial_game(t_game *game)
{
    game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	initial_player(&game->player);
	initial_textures(game->textures);
}