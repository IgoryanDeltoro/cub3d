/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:53:53 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/02 11:50:45 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	select_texture(t_game *game)
{
	if (game->ray_c.side == 0)
	{
		if (game->ray_c.ray_dir_x > 0)
			game->ray_c.tex_index = 2;
		else
			game->ray_c.tex_index = 3;
	}
	else
	{
		if (game->ray_c.ray_dir_y > 0)
			game->ray_c.tex_index = 1;
		else
			game->ray_c.tex_index = 0;
	}
}

void	put_pixel_to_buffer(t_img *buffer, int x, int y, int color)
{
	char	*dst;

	dst = buffer->addr + (y * buffer->line_length + x * (buffer->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	take_player_position(t_game *game)
{
	game->ray_c.map_x = (int)game->player.x;
	game->ray_c.map_y = (int)game->player.y;
}
