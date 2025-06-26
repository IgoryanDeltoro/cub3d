/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:01 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 21:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return 0;
}

int handle_key_press(int keycode, t_game *game)
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

int run_game(t_game *game)
{
    // game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");

    mlx_hook(game->win, 2, 1L<<0, handle_key_press, game);     // Key press
    mlx_hook(game->win, 17, 0, close_game, game);       // Red cross
    mlx_loop_hook(game->mlx, render_map, game);
    mlx_loop(game->mlx);
    return 1;
}

 int parse_cub_file(char *filename, t_game *game)
{
    (void)filename;
    // int fd = open(filename, O_RDONLY);
    // // char *line;

    // if (fd < 0)
    //     exit_with_error(NULL, "Failed to open .cub file");

    // // Fill with parsing logic (textures, colors, map)
    // // Placeholder:
    game->map = malloc(sizeof(char *) * 6);
    game->map[0] = strdup("1111111111111111");
    game->map[1] = strdup("1000011110000001");
    game->map[2] = strdup("1000N00000000001");
    game->map[3] = strdup("1111111111111111");
    game->map[4] = NULL;

    game->floor_color = rgb_to_int(100, 100, 100);
    game->ceiling_color = rgb_to_int(50, 50, 50);

    game->player.x = 3.5;
    game->player.y = 2.5;
    game->player.dir_x = -1;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0.66;

    // close(fd);
    return 1;
}