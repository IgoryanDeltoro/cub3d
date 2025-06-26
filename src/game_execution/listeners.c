/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:04:10 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/26 12:07:42 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int handle_button_listeners(int keycode, t_game *game)
{
    double old_dir_x, old_plane_x;

    if (keycode == 65307)
        close_game(game); // your cleanup + exit function

    // Move forward
    if (keycode == 65362 || keycode == 119)
    {
        if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.dir_x * MOVE_SPEED)] != '1')
            game->player.x += game->player.dir_x * MOVE_SPEED;
        if (game->map[(int)(game->player.y + game->player.dir_y * MOVE_SPEED)][(int)(game->player.x)] != '1')
            game->player.y += game->player.dir_y * MOVE_SPEED;
    }

    // Move backward
    if (keycode == 65364 || keycode == 115)
    {
        if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.dir_x * MOVE_SPEED)] != '1')
            game->player.x -= game->player.dir_x * MOVE_SPEED;
        if (game->map[(int)(game->player.y - game->player.dir_y * MOVE_SPEED)][(int)(game->player.x)] != '1')
            game->player.y -= game->player.dir_y * MOVE_SPEED;
    }

    // Move left (strafe)
    // if (keycode == XK_a)
    // {
    //     double perp_x = -game->player.dir_y;
    //     double perp_y = game->player.dir_x;
    //     if (game->map[(int)(game->player.y)][(int)(game->player.x + perp_x * MOVE_SPEED)] != '1')
    //         game->player.x += perp_x * MOVE_SPEED;
    //     if (game->map[(int)(game->player.y + perp_y * MOVE_SPEED)][(int)(game->player.x)] != '1')
    //         game->player.y += perp_y * MOVE_SPEED;
    // }

    // // Move right (strafe)
    // if (keycode == XK_d)
    // {
    //     double perp_x = game->player.dir_y;
    //     double perp_y = -game->player.dir_x;
    //     if (game->map[(int)(game->player.y)][(int)(game->player.x + perp_x * MOVE_SPEED)] != '1')
    //         game->player.x += perp_x * MOVE_SPEED;
    //     if (game->map[(int)(game->player.y + perp_y * MOVE_SPEED)][(int)(game->player.x)] != '1')
    //         game->player.y += perp_y * MOVE_SPEED;
    // }

    // Rotate right
    if (keycode == 65363 || keycode == 100)
    {
        old_dir_x = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
        game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
        old_plane_x = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - game->player.plane_y * sin(-ROT_SPEED);
        game->player.plane_y = old_plane_x * sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
    }

    // Rotate left
    if (keycode == 65361 || keycode == 97)
    {
        old_dir_x = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
        game->player.dir_y = old_dir_x * sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
        old_plane_x = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - game->player.plane_y * sin(ROT_SPEED);
        game->player.plane_y = old_plane_x * sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
    }

    return (0);
}