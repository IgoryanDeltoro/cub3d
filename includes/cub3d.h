/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:16:23 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:16:23 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "error_message.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				**map;
	int					map_width;
	int					map_height;
	int					player_x;
	int					player_y;
}						t_game;

void    validate_imputs(int ac, char *str);
void    initial_game(t_game *game);
void	print_error(char *str);
void    exit_with_error(t_game *game, char *error);

#endif