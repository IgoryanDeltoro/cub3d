#include "../../includes/cub3d.h"

char	*cup3_trim(char *str)
{
	char	*temp;

	temp = ft_strtrim(str, " \t\n");
	free(str);
	if (!temp)
		return (str = NULL, str);
	return (temp);
}

char	*utils_str_join(char *str1, char *str2)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str1 || !str2)
	{
		if (str2)
			return (free(str2), str2 = NULL, NULL);
		else if (str1)
			return (free(str1), str1 = NULL, NULL);
		else
			return (NULL);
	}
	temp = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!temp)
		return (free(str1), free(str2), str1 = NULL, str2 = NULL, NULL);
	while (str1[++i])
		temp[i] = str1[i];
	while (str2[j])
		temp[i++] = str2[j++];
	temp[i] = '\0';
	(free(str1), free(str2));
	return (str1 = NULL, str2 = NULL, temp);
}

void free_2d(char **str)
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


int	pars_no_so_we_ea(t_game *game, char **texture, char *str)
{
	if (str)
		free_2d(texture), exit_with_error(game, MAL);
	str = ft_strdup(texture[1]);
	if (!str)
		free_2d(texture), exit_with_error(game, MAL);
	return (0);
}

void	pars_texture(t_game *game, char *temp, int *count, int n)
{
	char	**texture;
	int		len;

	len = ft_strlen(temp);
	temp = cup3_trim(temp);
	texture = NULL;
	if (len >= n && (temp[n] == ' ' || temp[n] == '\t'))
		texture = ft_split(temp, temp[n]);
	else
		free(temp), exit_with_error(game, ICM);
	if (!texture)
		free(temp), exit_with_error(game, MAL);
	if (texture[1] == NULL || texture[2] != NULL)
		free(temp), free_2d(texture), exit_with_error(game, ICM);
	else
	{
		free(temp);
		if (ft_strcmp(texture[0], "NO") == 0)
			pars_no_so_we_ea(game, texture, game->no);
		else if (ft_strcmp(texture[0], "SO") == 0)
			pars_no_so_we_ea(game, texture, game->so);
		else if (ft_strcmp(texture[0], "WE") == 0)
			pars_no_so_we_ea(game, texture, game->we);
		else if (ft_strcmp(texture[0], "EA") == 0)
			pars_no_so_we_ea(game, texture, game->ea);
		*count += 1;
	}
}

char	**pars_check_valid_collor(t_game *game, char **str)
{
	int		i;
	char	**res;

	i = -1;
	while (str[1][++i])
	{
		if (str[1][i] == ',')
		{
			if (!ft_isdigit(str[1][i + 1]))
				return (NULL);
		}
		else
		{
			if (!ft_isdigit(str[1][i]))
				return (NULL);
		}
	}
	res = ft_split(str[1], ',');
	if (!res)
		free_2d(str), exit_with_error(game, MAL);
	i = 0;
	while (res[i])
		i++;
	if (i != 3)
		free_2d(res), free_2d(str), exit_with_error(game, ICM);
	return (res);
}

int	pars_init_collor(t_game *game, char **collor)
{
	char	**res;
	char	*temp;
	int		i;

	i = -1;
	temp = ft_strtrim(collor[1], " \n\t");
	if (!temp)
		return (free_2d(collor), exit_with_error(game, MAL), 0);
	free(collor[1]);
	collor[1] = temp;
	res = pars_check_valid_collor(game, collor);
	if (!res)
		free_2d(collor), exit_with_error(game, ICM);
	if (ft_strcmp(collor[0], "F") == 0)
		while(res[++i])
			game->floor_color[i] = ft_atoi(res[i]);
	else if (ft_strcmp(collor[0], "C") == 0)
		while(res[++i])
			game->ceiling_color[i] = ft_atoi(res[i]);
	return (free_2d(res), 0);
}

int	pars_collor(t_game *game, char *temp, int *col, int n)
{
	char	**collor;
	int		len;

	collor = NULL;
	len = ft_strlen(temp);
	if (len >= n && (temp[n] == ' ' || temp[n] == '\t'))
		collor = ft_split(temp, temp[n]);
	else
		free(temp), exit_with_error(game, ICM);
	free(temp);
	if (!collor)
		exit_with_error(game, MAL);
	if (collor[1] == NULL || collor[2] != NULL)
		free_2d(collor), exit_with_error(game, ICM);
	*col += 1;
	pars_init_collor(game, collor);
	return (free_2d(collor), 0);
}

char	*pars_create_map_string(t_game *game, char *map_str, char *temp)
{
	int	i;

	i = 0;
	while (temp[i] && !ft_isdigit(temp[i]))
		i++;
	if (temp[i] == '\0')
	{
		if (map_str)
			free(map_str);
		free(temp), exit_with_error(game, ICM);
	}
	if (map_str == NULL)
		map_str = utils_str_join(ft_strdup(""), temp);
	else
		map_str = utils_str_join(map_str, temp);
	if (!map_str)
		free(map_str), exit_with_error(game, MAL);
	return (map_str);
}

int	pars_check_item(char **map, int i, int j, char ch)
{
	if (ch == 'N')
	{
		if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t' || map[i + 1][j] == '\n'
			|| map[i + 1][j] == '\0' || map[i - 1][j] == ' ' 
			|| map[i - 1][j] == '\t' || map[i - 1][j] == '\n'
			|| map[i - 1][j] == '\0' || map[i][j + 1] == ' '
			|| map[i][j + 1] == '\t' || map[i][j + 1] == '\n'
			|| map[i][j + 1] == '\0' || map[i][j - 1] == ' '
			|| map[i][j - 1] == '\t' || map[i][j - 1] == '\n'
			|| map[i][j - 1] == '\0')
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

int pars_map_1(t_game *game, int i, int *n)
{
	int	j;

	j = -1;
	while (game->map[i][++j])
	{
		if (game->map[i][j] != ' ' && game->map[i][j] != '\t')
		{
			if (game->map[i][j] == 'N')
			{
				if (*n > 0 || i == 0 || j == 0 || game->map[i + 1] == NULL
						|| game->map[i][j + 1] == '\n' || pars_check_item(game->map, i , j, 'N'))
					return (2);
				game->player.y = i;
				game->player.x = j;
				*n += 1;
			}
			else if (game->map[i][j] == '0' && pars_check_item(game->map, i , j, '0'))
				return (2);
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				printf("yes\n");
				return (2);
			}
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
	game->map = ft_split(map_str, '\n');
	if (!game->map)
		free(map_str), exit_with_error(game, MAL);
	while (game->map[++i])
	{
		if (pars_map_1(game, i, &n))
			return (2);
	}
	return (0);
}

int	read_map(t_game *game)
{
	char 	*temp;
	char	*map_str;
	int		count;
	int		col;

	count = 0;
	col = 0;
	map_str = NULL;
	while (1)
	{
		temp = get_next_line(game->fd);
		if (temp == NULL)
			break;
		if (pars_check_line(temp) && count < 4)
			pars_texture(game, temp, &count, 2);
		else if (pars_check_line(temp) && col < 2)
			pars_collor(game, temp, &col, 1);
		else if (col == 2 && count == 4)
			map_str = pars_create_map_string(game, map_str, temp);
	}
	if (map_str && pars_map(game, map_str))
		free(map_str), exit_with_error(game, ICM);
    return (0);
}
