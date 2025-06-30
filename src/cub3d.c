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

	(void)ac;
	initial_game(&game);
	validate_imputs(&game, ac, av[1]);
	
	
	init_mlx(&game); 
	
	read_map(&game);
	for (int i = 0; game.map[i]; i++)
	{
		printf("%s\n", game.map[i]);
	}
	return (free_game(&game), 0);
}
