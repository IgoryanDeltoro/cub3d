/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:00:14 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/02 11:48:49 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_right(t_game *game)
{
	double	prev_dir_x;
	double	prev_plane_x;

	prev_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x
		* cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
	game->player.dir_y = prev_dir_x
		* sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
	prev_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x
		* cos(-ROT_SPEED) - game->player.plane_y * sin(-ROT_SPEED);
	game->player.plane_y = prev_plane_x
		* sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
}

void	rotate_left(t_game *game)
{
	double	prev_dir_x;
	double	prev_plane_x;

	prev_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x
		* cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
	game->player.dir_y = prev_dir_x
		* sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
	prev_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x
		* cos(ROT_SPEED) - game->player.plane_y * sin(ROT_SPEED);
	game->player.plane_y = prev_plane_x
		* sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
}

int	handle_button_listeners(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 65362 || keycode == 119)
		move_forward(game);
	else if (keycode == 65364 || keycode == 115)
		move_backward(game);
	else if (keycode == 97)
		move_left(game);
	else if (keycode == 100)
		move_right(game);
	else if (keycode == 65363)
		rotate_right(game);
	else if (keycode == 65361)
		rotate_left(game);
	return (0);
}

int	close_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
	}
	if (game->screen_buffer.img)
		mlx_destroy_image(game->mlx, game->screen_buffer.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_game(game);
	exit(0);
	return (0);
}

bool	run_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		return (false);
	game->screen_buffer.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->screen_buffer.img)
		return (false);
	game->screen_buffer.addr = mlx_get_data_addr(
			game->screen_buffer.img,
			&game->screen_buffer.bits_per_pixel,
			&game->screen_buffer.line_length,
			&game->screen_buffer.endian);
	if (!game->screen_buffer.addr)
		return (false);
	mlx_hook(game->win, 2, 1L << 0, handle_button_listeners, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	return (true);
}
