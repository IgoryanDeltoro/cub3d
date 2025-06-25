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

int	read_map(t_game *data, char **av)
{
	char 	*temp;
	int		fd;
    int     n;
    int     n_line;
    int     i;

    i = -1;
	fd = open(av[1], O_RDONLY);
	temp = get_next_line(fd);
     if (!data->map)
        return  (NULL);
    data->map = ft_split(temp, '\n');
    if (!data->map)
        return  (NULL);
    return (close(fd), 0);
}