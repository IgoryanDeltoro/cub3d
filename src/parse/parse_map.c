#include "../../includes/cub3d.h"

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
		return (NULL);
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
		if (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '/n')
			return (1);
	}
	return (0);
}

int pars_find_N(char *s)
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (s[i + 1] == '\n')
				return (2);
		}
		else if (s[i] == 'N')
			n++;
		else if (s[i] != '0' && s[i] != '1')
			return (2);
	}
	return (n);
}

int	pars_no_so_we_ea(t_game *game, char **texture, char *str)
{
	if (str)
		free_2d(texture), exit_with_error(game, MAL);
	str = ft_strdup(texture[1]);
	if (!str)
		free_2d(texture), exit_with_error(game, MAL);
}

void	pars_texture(t_game *game, char *temp, int *count, int n)
{
	char	**texture;
	int		len;

	len = ft_strlen(temp);
	if (len >= n && temp[n] == ' ' || temp[n] == '\t')
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
			pars_no_so_we_ea(game, texture[1], game->no);
		else if (ft_strcmp(texture[0], "SO") == 0)
			pars_no_so_we_ea(game, texture[1], game->so);
		else if (ft_strcmp(texture[0], "WE") == 0)
			pars_no_so_we_ea(game, texture[1], game->we);
		else if (ft_strcmp(texture[0], "EA") == 0)
			pars_no_so_we_ea(game, texture[1], game->ea);
		*count += 1;
	}
}

char	**pars_check_valid_collor(t_game *game, char **str)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	while (str[1][i])
	{
		if (str[i] == ',' && !ft_isdigit(str[1][i + 1]))
			return (NULL);
		else if (!ft_isdigit(str[1][i]))
			return (NULL);
		i++;
	}
	res = ft_split(str[1], ',');
	if (!res)
		free_2d(str), exit_with_error(game, MAL);
	i = 0;
	while (res[i])
		i++;
	if (len != 3)
		free_2d(res), free_2d(str), exit_with_error(game, MAL);
	return (res);
}

int	pars_init_collor(t_game *game, char **collor)
{
	char	**res;
	int		i;

	i = -1;
	res = pars_check_valid_collor(game, collor);
	if (!res)
		free_2d(collor), exit_with_error(game, ICM);
	if (ft_strcmp(collor[0], "F") == 0)
	{
		while(res[++i])
			game->floor_color[i] = ft_atoi(res[i]);
	}
	else if (ft_strcmp(collor[0], "C") == 0)
	{
		while(res[++i])
			game->floor_color[i] = ft_atoi(res[i]);
	}
	else
		free_2d(collor), exit_with_error(game, ICM);
	return (free_2d(res), 0);
}

int	pars_collor(t_game *game, char *temp, int *col, int n)
{
	char	**collor;
	int		len;

	len = ft_strlen(temp);
	if (len >= n && temp[n] == ' ' || temp[n] == '\t')
		collor = ft_split(temp, temp[n]);
	else
		free(temp), exit_with_error(game, ICM);
	if (!collor)
		exit_with_error(game, MAL);
	if (collor[1] == NULL || collor[2] != NULL)
		free(temp), free_2d(collor), exit_with_error(game, ICM);
	free(temp);
	pars_init_collor(game, collor);
	return (free_2d(collor), 0);
}

int	pars_create_map_string(t_game *game, char *map_str, char *temp)
{
	if (map_str == NULL)
		map_str = utils_str_join(ft_strdup(""), temp);
	else
		map_str = utils_str_join(map_str, temp);
	if (!map_str)
		free(map_str), exit_with_error(game, MAL);
	return (free(temp), 0);
}

int	pars_check_item(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] == ' ' || game->map[i][j + 1] == '\t'
			|| game->map[i][j + 1] == '\n' || game->map[i][j + 1] == '\0')
		return (1);
	else if (game->map[i][j - 1] == ' ' || game->map[i][j - 1] == '\t'
			|| game->map[i][j - 1] == '\n' || game->map[i][j - 1] == '\0')
		return (1);
	else if (game->map[i + 1][j] == ' ' || game->map[i + 1][j] == '\t'
			|| game->map[i + 1][j] == '\n' || game->map[i + 1][j] == '\0')
		return (1);
	else if (game->map[i - 1][j] == ' ' || game->map[i - 1][j] == '\t'
			|| game->map[i - 1][j] == '\n' || game->map[i - 1][j] == '\0')
		return (1);
}

int	pars_map(t_game *game, char *map_str)
{
	int	i;
	int	j;

	i = -1;
	game->map = ft_split(map_str, '\n');
	if (!game->map)
		free(map_str), exit_with_error(game, MAL);
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N')
			{
				game->player.y = i;
				game->player.x = j;
			}
			if (((i == 0 || game->map[i + 1] == NULL) || (j == 0 || game->map[i][j + 1] == '\0'))
				&& game->map[i][j] != '1')
				return (2);
			else if (game->map[i][j] == '0' && pars_check_item(game, i , j))
				return (2);
		}
	}
	return (0);
}

int	read_map(t_game *game, char **av)
{
	char 	*temp;
	char	*map_str;
	int		count;
	int		col;

	count = 0;
	col = 0;
	map_str = NULL;
	game->fd = open(av[1], O_RDONLY);
	while (1)
	{
		temp = get_next_line(game->fd);
		if (temp == NULL)
			break;
		if (pars_check_line(temp) && count <= 4)
			pars_texture(game, temp, &count, 2);
		else if (pars_check_line(temp) && col <= 2)
			pars_collor(game, temp, &col, 1);
		else if (pars_check_line(temp))
			pars_create_map_string(game, map_str, temp);
	}
	if (pars_find_N(map_str) != 1 || pars_map(game, map_str))
		free(map_str), exit_with_error(game, ICM);
    return (0);
}
