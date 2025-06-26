/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:15:47 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 22:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error(NULL, FIM);
}

void	load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		exit_with_error(NULL, "Failed to load texture");

	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
}
void	init_textures(t_game *game)
{
	load_texture(game, &game->textures[1], "../../assets/textures/wall.xpm");
	load_texture(game, &game->textures[0], "../../assets/textures/wall.xpm");
	load_texture(game, &game->textures[2], "../../assets/textures/wall.xpm");
	load_texture(game, &game->textures[3], "../../assets/textures/wall.xpm");
}