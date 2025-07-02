// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   listeners.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/06/26 12:04:10 by ibondarc          #+#    #+#             */
// /*   Updated: 2025/06/27 10:24:03 by marvin           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/cub3d.h"

// void rotate_right(t_game *game)
// {
//     double prev_dir_x;
//     double prev_plane_x;
    
//     prev_dir_x = game->player.dir_x;
//     game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - game->player.dir_y * sin(-ROT_SPEED);
//     game->player.dir_y = prev_dir_x * sin(-ROT_SPEED) + game->player.dir_y * cos(-ROT_SPEED);
//     prev_plane_x = game->player.plane_x;
//     game->player.plane_x = game->player.plane_x * cos(-ROT_SPEED) - game->player.plane_y * sin(-ROT_SPEED);
//     game->player.plane_y = prev_plane_x * sin(-ROT_SPEED) + game->player.plane_y * cos(-ROT_SPEED);
// }

// void rotate_left(t_game *game)
// {
//     double prev_dir_x;
//     double prev_plane_x;
    
//     prev_dir_x = game->player.dir_x;
//     game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - game->player.dir_y * sin(ROT_SPEED);
//     game->player.dir_y = prev_dir_x * sin(ROT_SPEED) + game->player.dir_y * cos(ROT_SPEED);
//     prev_plane_x = game->player.plane_x;
//     game->player.plane_x = game->player.plane_x * cos(ROT_SPEED) - game->player.plane_y * sin(ROT_SPEED);
//     game->player.plane_y = prev_plane_x * sin(ROT_SPEED) + game->player.plane_y * cos(ROT_SPEED);
// }

// int handle_button_listeners(int keycode, t_game *game)
// {
//     if (keycode == 65307)
//         close_game(game);
//     else if (keycode == 65362 || keycode == 119)
//         move_forward(game);
//     else if (keycode == 65364 || keycode == 115)
//         move_backward(game);
//     else if (keycode == 65361)
//         move_left(game);
//     else if (keycode == 65363)
//         move_right(game);
//     else if (keycode == 100)
//         rotate_right(game);
//     else if (keycode == 97)
//         rotate_left(game);
//     return (0);
// }