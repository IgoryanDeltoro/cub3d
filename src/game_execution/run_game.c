/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:00:14 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/01 21:29:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return 0;
}

void run_game(t_game *game)
{
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
    if (!game->win)
        exit_with_error(game, FCW);
    game->screen_buffer.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    
    // 2. Get the address of the image's memory buffer
    // mlx_get_data_addr returns a char* to the buffer and fills the
    // other integers with information about the buffer's layout.
    game->screen_buffer.addr = mlx_get_data_addr(
        game->screen_buffer.img_ptr, 
        &game->screen_buffer.bits_per_pixel,
        &game->screen_buffer.line_length, 
        &game->screen_buffer.endian
    );
    mlx_hook(game->win, 2, 1L<<0, handle_button_listeners, game); 
    mlx_hook(game->win, 17, 0, close_game, game);   
    mlx_loop_hook(game->mlx, render_map, game);
    mlx_loop(game->mlx);
}