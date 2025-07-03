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

int	read_map_1(t_game *game, char *temp, char **map_str, int *count)
{
	if (pars_check_line(temp))
	{
		if ((ft_strncmp(temp, "C", 1) == 0
				|| ft_strncmp(temp, "F", 1) == 0) && *count < 6)
		{
			pars_color(game, temp, count, 1);
		}
		else if (*count < 6)
			pars_texture(game, temp, count, 2);
		else if (*map_str || pars_check_line(temp))
			*map_str = pars_create_map_string(game, map_str, temp);
	}
	else
		free(temp);
	return (0);
}

int	read_map(t_game *game)
{
	char	*temp;
	char	*map_str;
	int		count;

	count = 0;
	map_str = NULL;
	while (1)
	{
		temp = get_next_line(game->fd);
		if (temp == NULL)
			break ;
		read_map_1(game, temp, &map_str, &count);
	}
	if (pars_map(game, map_str))
		(free(map_str), exit_with_error(game, ICM));
	return (free(map_str), 0);
}

void	validate_imputs(t_game *game, int ac, char *str)
{
	int	len;

	(void)str;
	(void)ac;
	if (ac != 2)
		exit_with_error(NULL, FD);
	len = ft_strlen(str);
	if (ft_strcmp(&str[len - 4], ".cub") != 0)
		exit_with_error(NULL, WN);
	if (len < 5 || !ft_strcmp(&str[len - 5], "/.cub"))
		exit_with_error(NULL, TSN);
	game->fd = open(str, O_RDONLY);
	if (game->fd < 0)
		exit_with_error(NULL, NVP);
}
