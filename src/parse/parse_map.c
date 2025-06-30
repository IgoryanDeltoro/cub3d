/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:01 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/27 21:14:47 by marvin           ###   ########.fr       */
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

    game->map = malloc(sizeof(char *) * 9);
                                 //WEST
    game->map[0] = strdup("1111111111111111");
    game->map[1] = strdup("1000000110000001");
    game->map[2] = strdup("1000000110000001");
    game->map[3] = strdup("1000000000000001"); //NORTH
    game->map[4] = strdup("1000000000000001");
    game->map[5] = strdup("1100000000000001");
    game->map[6] = strdup("1000000N00000011");
    game->map[7] = strdup("1111111111111111");
    game->map[8] = NULL;       //EAST  

    game->floor_color = rgb_to_int(100, 100, 100);
    game->ceiling_color = rgb_to_int(50, 50, 50);

    game->player.x = 7.5;
    game->player.y = 6.5;
    game->player.dir_x = -1;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0.66;

    return 1;
}