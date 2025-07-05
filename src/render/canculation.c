/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/02 11:50:45 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_perp_wall_dist(t_game *game)
{
	double	y;
	double	x;

	if (game->ray_c.side == 0)
	{
		x = (game->ray_c.map_x - game->player.x + (1 - game->ray_c.step_x)
				/ 2);
		game->ray_c.perp_wall_dist = x / game->ray_c.ray_dir_x;
	}
	else
	{
		y = (game->ray_c.map_y - game->player.y + (1 - game->ray_c.step_y)
				/ 2);
		game->ray_c.perp_wall_dist = y / game->ray_c.ray_dir_y;
	}
}

void	calculate_dist(t_game *game)
{
	if (game->ray_c.ray_dir_x == 0)
		game->ray_c.delta_dist_x = 1e30;
	else
		game->ray_c.delta_dist_x = fabs(1 / game->ray_c.ray_dir_x);
	if (game->ray_c.ray_dir_y == 0)
		game->ray_c.delta_dist_y = 1e30;
	else
		game->ray_c.delta_dist_y = fabs(1 / game->ray_c.ray_dir_y);
}

void	calculate_ray_dir(t_game *game, int x)
{
	double	x_dir;
	double	y_dir;
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	x_dir = game->player.dir_x + game->player.plane_x * camera_x;
	y_dir = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray_c.ray_dir_x = x_dir;
	game->ray_c.ray_dir_y = y_dir;
}

void	calculate_wall_slice_height(t_game *game)
{
	game->ray_c.line_height = (int)(HEIGHT / game->ray_c.perp_wall_dist);
	game->ray_c.draw_start = -game->ray_c.line_height / 2 + HEIGHT / 2;
	if (game->ray_c.draw_start < 0)
		game->ray_c.draw_start = 0;
	game->ray_c.draw_end = game->ray_c.line_height / 2 + HEIGHT / 2;
	if (game->ray_c.draw_end >= HEIGHT)
		game->ray_c.draw_end = HEIGHT - 1;
}
