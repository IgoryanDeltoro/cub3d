/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:15:47 by ibondarc          #+#    #+#             */
/*   Updated: 2025/07/03 14:33:37 by ibondarc         ###   ########.fr       */
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

bool	handle_loading_t(t_game *game, char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (i < 4)
	{
		if (!load_texture(game, &game->textures[i], str[i]))
			return (free(str), false);
		i++;
	}
	free(str);
	return (true);
}

char	**make_arr(char *s1, char *s2, char *s3, char *s4)
{
	char	**dest;

	dest = NULL;
	dest = ft_calloc(sizeof(char *), 5);
	if (!dest)
		return (NULL);
	dest[0] = s1;
	dest[1] = s2;
	dest[2] = s3;
	dest[3] = s4;
	return (dest);
}

bool	init_textures(t_game *game)
{
	if (game->map[(int)game->player.y][(int)game->player.x] == 'N')
	{
		if (!handle_loading_t(game, make_arr(game->ea, game->we, game->no, game->so)))
			return (false);
	}
	else if (game->map[(int)game->player.y][(int)game->player.x] == 'S')
	{
		if (!handle_loading_t(game, make_arr(game->we, game->ea, game->so, game->no)))
			return (false);
	}
	else if (game->map[(int)game->player.y][(int)game->player.x] == 'E')
	{
		if (!handle_loading_t(game, make_arr(game->so, game->no, game->ea, game->we)))
			return (false);
	}
	if (game->map[(int)game->player.y][(int)game->player.x] == 'W')
	{
		if (!handle_loading_t(game, make_arr(game->no, game->so, game->we, game->ea)))
			return (false);
	}
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
