/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:04:12 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	game->map_width = -1;
	game->map_height = -1;
}
/*
game->player_x = -1;
game->player_y = -1;
*/
