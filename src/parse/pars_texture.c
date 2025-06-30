/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	pars_check_line(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (1);
	}
	return (0);
}

int	pars_no_so_we_ea(t_game *game, char **texture, char **str)
{
	if (*str)
		(free_2d(texture), exit_with_error(game, MAL));
	else
	{
		*str = ft_strdup(texture[1]);
		if (!*str)
			(free_2d(texture), exit_with_error(game, MAL));
	}
	return (0);
}

int	pars_texture_1(t_game *game, char **texture)
{
	if (ft_strcmp(texture[0], "NO") == 0)
		pars_no_so_we_ea(game, texture, &game->no);
	else if (ft_strcmp(texture[0], "SO") == 0)
		pars_no_so_we_ea(game, texture, &game->so);
	else if (ft_strcmp(texture[0], "WE") == 0)
		pars_no_so_we_ea(game, texture, &game->we);
	else if (ft_strcmp(texture[0], "EA") == 0)
		pars_no_so_we_ea(game, texture, &game->ea);
	return (0);
}

int	pars_texture(t_game *game, char *temp, int *count, int n)
{
	char	**texture;
	int		len;
	char	*trim;

	texture = NULL;
	len = ft_strlen(temp);
	trim = ft_strtrim(temp, " \t\n");
	if (!trim)
		return (free(temp), exit_with_error(game, MAL));
	free(temp);
	temp = trim;
	if (len >= n && (temp[n] == ' ' || temp[n] == '\t'))
		texture = ft_split(temp, temp[n]);
	else
		(free(temp), exit_with_error(game, ICM));
	if (!texture)
		(free(temp), exit_with_error(game, MAL));
	if (texture[1] == NULL || texture[2] != NULL)
		(free(temp), free_2d(texture), exit_with_error(game, ICM));
	else
		(free(temp), pars_texture_1(game, texture));
	return (*count += 1, free_2d(texture), 0);
}
