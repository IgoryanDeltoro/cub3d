/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:15:47 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/02 11:38:08 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	load_texture(t_game *game, t_textures *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (false);
	tex->data = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->data)
		return (false);
	return (true);
}

bool	init_textures(t_game *game)
{
	if (!load_texture(game, &game->textures[0], game->no))
		return (false);
	if (!load_texture(game, &game->textures[1], game->so))
		return (false);
	if (!load_texture(game, &game->textures[2], game->we))
		return (false);
	if (!load_texture(game, &game->textures[3], game->ea))
		return (false);
	return (true);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error(NULL, FIM);
	if (!init_textures(game))
		exit_with_error(NULL, FLT);
}
