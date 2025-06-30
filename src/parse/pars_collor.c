/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_collor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	pars_check_valid_collor(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (!ft_isdigit(str[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	pars_check_comma(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
		}
		i++;
	}
	if (count > 2)
		return (1);
	return (0);
}

int	pars_init_collor(t_game *game, char **collor)
{
	char	**res;
	int		i;

	i = -1;
	if (pars_check_comma(collor[1]))
		return (free_2d(collor), exit_with_error(game, ICM));
	res = ft_split(collor[1], ',');
	if (!res)
		(free_2d(collor), exit_with_error(game, ICM));
	while (res[++i])
		if (pars_check_valid_collor(res[i]))
			return (free_2d(res), free_2d(collor), exit_with_error(game, ICM));
	if (i > 3)
		return (free_2d(res), free_2d(collor), exit_with_error(game, ICM));
	i = -1;
	if (ft_strcmp(collor[0], "F") == 0)
		while (res[++i])
			game->floor_color[i] = ft_atoi(res[i]);
	else if (ft_strcmp(collor[0], "C") == 0)
		while (res[++i])
			game->ceiling_color[i] = ft_atoi(res[i]);
	else
		return (free_2d(res), free_2d(collor), exit_with_error(game, ICM));
	return (free_2d(res), 0);
}

int	pars_collor(t_game *game, char *temp, int *col, int n)
{
	char	**collor;
	char	*trim;

	collor = ft_calloc(sizeof(char *), 3);
	if (!collor)
		return (free(temp), exit_with_error(game, MAL));
	collor[0] = ft_substr(temp, 0, n);
	if (!collor[0])
		return (free(temp), exit_with_error(game, MAL));
	collor[1] = ft_substr(temp, n, ft_strlen(temp));
	if (!collor[1])
		return (free(temp), exit_with_error(game, MAL));
	trim = ft_strtrim(collor[1], " \t\n");
	if (!temp)
		return (free(temp), exit_with_error(game, MAL));
	free(collor[1]);
	collor[1] = trim;
	free(temp);
	*col += 1;
	pars_init_collor(game, collor);
	return (free_2d(collor), 0);
}
