/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

ssize_t	ft_str_chr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*cub_trim(t_game *game, char **temp)
{
	char	*trim;

	trim = ft_strtrim(*temp, " \t");
	if (!*trim)
		return (free(*temp), exit_with_error(game, MAL), NULL);
	free(*temp);
	return (trim);
}

int	read_map_1(t_game *game, char *temp, char **map_str, int *count)
{
	if (pars_check_line(temp))
	{
		if (*count == 7)
			return (free(temp), 1);
		if (*count < 6)
		{
			temp = cub_trim(game, &temp);
		}
		if ((ft_strncmp(temp, "C", 1) == 0
				|| ft_strncmp(temp, "F", 1) == 0) && *count < 6)
			pars_color(game, temp, count, 1);
		else if (*count < 6)
			pars_texture(game, temp, count, 2);
		else if (*map_str || pars_check_line(temp))
			*map_str = pars_create_map_string(game, map_str, temp);
		return (0);
	}
	if (*count == 6 && *map_str)
		*count += 1;
	return (free(temp), 0);
}

int	read_map(t_game *game)
{
	char	*temp;
	int		map_h;
	int		map_w;
	char	*map_str;
	int		count;

	count = 0;
	map_h = 0;
	map_str = NULL;
	while (1)
	{
		temp = get_next_line(game->fd);
		if (temp == NULL)
			break ;
		map_h++;
		map_w = ft_strlen(temp);
		if (map_h >= MAP_H_SIZE || map_w >= MAP_W_SIZE)
			(free(temp), free(map_str), exit_with_error(game, ICM));
		if (read_map_1(game, temp, &map_str, &count))
			(free(map_str), exit_with_error(game, ICM));
	}
	if (pars_map(game, map_str))
		(free(map_str), exit_with_error(game, ICM));
	return (free(map_str), 0);
}

void	validate_imputs(t_game *game, int ac, char *str)
{
	int	len;

	if (ac != 2)
		exit_with_error(game, FD);
	len = ft_strlen(str);
	if (ft_strcmp(&str[len - 4], ".cub") != 0)
		exit_with_error(game, WN);
	if (len < 5 || !ft_strcmp(&str[len - 5], "/.cub"))
		exit_with_error(game, TSN);
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
	{
		write(2, IFD, ft_strlen(IFD));
		exit (1);
	}
}
