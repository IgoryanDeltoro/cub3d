/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/30 13:49:28 by marvin           ###   ########.fr       */
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
	initial_player(game);
	initial_textures(game->textures);
}
