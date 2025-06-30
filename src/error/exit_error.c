/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:32:54 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:08:06 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_game(t_game *game)
{
	close(game->fd);
	if (game->map)
		free_2d(game->map);
	if (game->no)
		free(game->no);
	if (game->ea)
		free(game->ea);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	return (0);
}

int	exit_with_error(t_game *game, char *error)
{
	if (game)
		free_game(game);
	if (error)
		print_error(error);
	exit(1);
	return (0);
}
