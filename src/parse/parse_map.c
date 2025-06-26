/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:01 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/26 12:04:32 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int rgb_to_int(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

 int parse_cub_file(char *filename, t_game *game)
{
    (void)filename;

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

    return 1;
}