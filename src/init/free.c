/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <rghazary@student.42vienna.com>     +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2025/07/04 12:29:25 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_2d(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

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
	char	*temp;

	while (1)
	{
		temp = get_next_line(game->fd);
		if (temp == NULL)
			break ;
		free(temp);
	}
	if (game)
		free_game(game);
	if (error)
		print_error(error);
	exit(1);
	return (0);
}

void	print_error(char *str)
{
	int	str_len;

	if (!str)
		return ;
	str_len = ft_strlen(str);
	write (2, str, str_len);
}
