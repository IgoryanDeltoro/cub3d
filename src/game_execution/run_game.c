/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:00:14 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/26 13:25:59 by ibondarc         ###   ########.fr       */
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
    mlx_hook(game->win, 2, 1L<<0, handle_button_listeners, game); 
    mlx_hook(game->win, 17, 0, close_game, game);   
    mlx_loop_hook(game->mlx, render_map, game);
    mlx_loop(game->mlx);
    return 1;
}