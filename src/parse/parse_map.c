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
		if (s[i] == 'N')
			n++;
	}
	return (n);
}

int	pars_texture(t_game *data, char *temp, int *count)
{
	char	**texture;

	texture = ft_split(temp, ' ');
	if (texture[1] == NULL)
		free_2d(texture), close(data->fd), exit_with_error(data, ICM);
	else
	{
		if (ft_strcmp(texture[0], "NO") == 0)
			data->
	}
	
}

int	read_map(t_game *data, char **av)
{
	char 	*temp;
	int		count;
	int		collor;
	int		n;

	(void)data;
	count = 0;
	collor = 0;
	n = 0;
	data->fd = open(av[1], O_RDONLY);
	while (1)
	{
		temp = get_next_line(data->fd);
		if (temp == NULL)
			break;
		n += pars_find_N(temp);
		if (pars_check_line(temp) && count <= 4)
			pars_texture(data, temp, &count);
		else if (pars_check_line(temp) && collor <= 2)
			pars_collor(data, temp, &collor);
		else
			pars_map(data, temp);
	}
    return (close(data->fd), 0);
}
