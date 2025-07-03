/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:44:42 by rghazary          #+#    #+#             */
/*   Updated: 2025/07/03 13:44:44 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	pars_check_valid_color(char *str)
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

char	*pars_create_map_string(t_game *game, char **map_str, char *temp)
{
	int	i;

	i = 0;
	if (*map_str)
	{
		while (temp[i] && !ft_isdigit(temp[i]))
			i++;
		if (temp[i] == '\0')
		{
			free(*map_str);
			(free(temp), exit_with_error(game, ICM));
			return (NULL);
		}
	}
	if (*map_str == NULL)
		*map_str = utils_str_join(ft_strdup(""), temp);
	else
		*map_str = utils_str_join(*map_str, temp);
	if (!*map_str)
		(free(*map_str), exit_with_error(game, MAL));
	return (*map_str);
}
