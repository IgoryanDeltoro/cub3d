/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:15:49 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:15:49 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char *av[])
{
	t_game	game;

	initial_game(&game);
	validate_imputs(&game, ac, av[1]);
	if (read_map(&game))
		return (free_game(&game), 0);
	init_mlx(&game);
	if (!run_game(&game))
	{
		print_error(FCW);
		close_game(&game);
	}
	return (free_game(&game), 0);
}
