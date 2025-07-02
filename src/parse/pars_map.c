/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2025/06/30 13:57:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*pars_create_map_string(t_game *game, char *map_str, char *temp)
{
	int	i;

	i = 0;
	if (map_str)
	{
		while (temp[i] && !ft_isdigit(temp[i]))
			i++;
		if (temp[i] == '\0')
		{
			free(map_str);
			(free(temp), exit_with_error(game, ICM));
			return (NULL);
		}
	}
	if (map_str == NULL)
		map_str = utils_str_join(ft_strdup(""), temp);
	else
		map_str = utils_str_join(map_str, temp);
	if (!map_str)
		(free(map_str), exit_with_error(game, MAL));
	return (map_str);
}
int	pars_check_item_1(char **map, int i, int j)
{
	if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E')
		return (2);
	if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'
		|| map[i + 1][j] == '\n' || map[i + 1][j] == '\0'
		|| map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
		|| map[i - 1][j] == '\n' || map[i - 1][j] == '\0'
		|| map[i][j + 1] == ' ' || map[i][j + 1] == '\t'
		|| map[i][j + 1] == '\n' || map[i][j + 1] == '\0'
		|| map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
		|| map[i][j - 1] == '\n' || map[i][j - 1] == '\0')
	{
		return (2);
	}
	return (0);
}

int	pars_check_item(char **map, int i, int j, bool val)
{
	if (val)
	{
		if (pars_check_item_1(map, i, j))
			return (2);
	}
	if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'
			|| map[i][j + 1] == '\n' || map[i][j + 1] == '\0')
		return (1);
	else if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
			|| map[i][j - 1] == '\n' || map[i][j - 1] == '\0')
		return (1);
	else if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'
			|| map[i + 1][j] == '\n' || map[i + 1][j] == '\0')
		return (1);
	else if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
			|| map[i - 1][j] == '\n' || map[i - 1][j] == '\0')
		return (1);
	return (0);
}

int	pars_map_1(t_game *game, int i, int *n)
{
	int	j;

	j = -1;
	while (game->map[i][++j])
	{
		if (game->map[i][j] != ' ' && game->map[i][j] != '\t')
		{
			if (ft_isalpha(game->map[i][j]))
			{
				if (*n > 0 || i == 0 || j == 0 || game->map[i + 1] == NULL
					|| game->map[i][j + 1] == '\n'
					|| game->map[i][j + 1] == '\0'
					|| pars_check_item(game->map, i, j, true))
					return (2);
				game->player.y = i;
				game->player.x = j;
				*n += 1;
			}
			else if (game->map[i][j] == '0'
				&& pars_check_item(game->map, i, j, false))
				return (2);
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (2);
		}
	}
	return (0);
}

int	pars_map(t_game *game, char *map_str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	if (map_str == NULL)
		return (1);
	game->map = ft_split(map_str, '\n');
	if (!game->map)
		(free(map_str), exit_with_error(game, MAL));
	while (game->map[++i])
	{
		if (pars_map_1(game, i, &n))
			return (2);
	}
	return (0);
}
