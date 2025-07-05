/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <rghazary@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	pars_init_color_2(int *value, char **res)
{
	int	arry[3];
	int	num;
	int	i;
	int	j;

	i = -1;
	while (res[++i])
	{
		num = ft_atoi(res[i]);
		j = 0;
		while (res[j] && (res[i][j] == '0'
			|| res[i][j] == ' ' || res[i][j] == '\t'))
			j++;
		if (num > 255 || num < 0 || (num == 0 && res[i][j] != '\0'))
			return (1);
		arry[i] = num;
	}
	*value = rgb_to_int(arry[0], arry[1], arry[2]);
	return (0);
}

int	pars_init_color_1(t_game *game, char **color, char **res)
{
	int	i;

	i = -1;
	if (res[0] && ft_strcmp(color[0], "C") == 0)
	{
		if (game->ceiling_color != -1
			|| pars_init_color_2(&game->ceiling_color, res))
			return (1);
		return (0);
	}
	else if (res[0] && ft_strcmp(color[0], "F") == 0)
	{
		if (game->floor_color != -1
			|| pars_init_color_2(&game->floor_color, res))
			return (1);
		return (0);
	}
	return (1);
}

int	pars_init_color(t_game *game, char **color)
{
	char	**res;
	int		i;

	i = -1;
	if (pars_check_comma(color[1]))
		return (free_2d(color), exit_with_error(game, CCM));
	res = ft_split(color[1], ',');
	if (!res)
		(free_2d(color), exit_with_error(game, CCM));
	while (res[++i])
	{
		if (pars_check_valid_color(res[i]))
			return (free_2d(res), free_2d(color), exit_with_error(game, CCM));
	}
	if (i != 3 || pars_init_color_1(game, color, res))
		return (free_2d(res), free_2d(color), exit_with_error(game, CCM));
	return (free_2d(res), 0);
}

int	pars_color(t_game *game, char *temp, int *col, int n)
{
	char	**color;
	char	*trim;

	color = ft_calloc(sizeof(char *), 3);
	if (!color)
		return (free(temp), exit_with_error(game, MAL));
	color[0] = ft_substr(temp, 0, n);
	if (!color[0])
		return (free(color), free(temp), exit_with_error(game, MAL));
	color[1] = ft_substr(temp, n, ft_strlen(temp));
	if (!color[1])
		return (free_2d(color), free(temp), exit_with_error(game, MAL));
	trim = ft_strtrim(color[1], " \t\n");
	if (!trim)
		return (free_2d(color), free(temp), exit_with_error(game, MAL));
	free(color[1]);
	color[1] = trim;
	free(temp);
	*col += 1;
	pars_init_color(game, color);
	return (free_2d(color), 0);
}
