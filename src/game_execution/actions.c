/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:36:36 by marvin            #+#    #+#             */
/*   Updated: 2025/06/26 16:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->player.y + game->player.dir_y * (MOVE_SPEED + COLL_MARGIN));
	x = (int)(game->player.x + game->player.dir_x * (MOVE_SPEED + COLL_MARGIN));
	if (game->map[(int)(game->player.y)][x] != '1')
		game->player.x += game->player.dir_x * MOVE_SPEED;
	if (game->map[y][(int)(game->player.x)] != '1')
		game->player.y += game->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->player.y - game->player.dir_y * (MOVE_SPEED + COLL_MARGIN));
	x = (int)(game->player.x - game->player.dir_x * (MOVE_SPEED + COLL_MARGIN));
	if (game->map[(int)(game->player.y)][x] != '1')
		game->player.x -= game->player.dir_x * MOVE_SPEED;
	if (game->map[y][(int)(game->player.x)] != '1')
		game->player.y -= game->player.dir_y * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	int		x;
	int		y;
	double	perp_x;
	double	perp_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	x = (int)(game->player.x + perp_x * (MOVE_SPEED + COLL_MARGIN));
	y = (int)(game->player.y + perp_y * (MOVE_SPEED + COLL_MARGIN));
	if (game->map[(int)(game->player.y)][x] != '1')
		game->player.x += perp_x * MOVE_SPEED;
	if (game->map[y][(int)(game->player.x)] != '1')
		game->player.y += perp_y * MOVE_SPEED;
}

void	move_right(t_game *game)
{
	int		y;
	int		x;
	double	perp_x;
	double	perp_y;

	perp_x = game->player.dir_y;
	perp_y = -game->player.dir_x;
	x = (int)(game->player.x + perp_x * (MOVE_SPEED + COLL_MARGIN));
	y = (int)(game->player.y + perp_y * (MOVE_SPEED + COLL_MARGIN));
	if (game->map[(int)(game->player.y)][x] != '1')
		game->player.x += perp_x * MOVE_SPEED;
	if (game->map[y][(int)(game->player.x)] != '1')
		game->player.y += perp_y * MOVE_SPEED;
}
