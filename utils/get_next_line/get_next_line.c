/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/10/17 12:35:15 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup_g(char **dest, char **src)
{
	int		i;
	size_t	count;

	i = 0;
	count = ft_strlen(*src);
	*dest = (char *)malloc((count + 1) * sizeof(char));
	if (*dest != NULL)
	{
		while ((*src)[i] != '\0')
		{
			(*dest)[i] = (*src)[i];
			i++;
		}
		(*dest)[i] = '\0';
	}
	free(*src);
	*src = NULL;
	return (*dest);
}

char	*ft_str_join(char **str1, char **str2, ssize_t *count)
{
	char	*temp;
	size_t	len;
	size_t	i;
	size_t	j;

	temp = NULL;
	if (ft_str_chr(*str2) >= 0)
		*count = 0;
	if (*str1 == NULL)
		return (ft_strdup_g(&*str1, &*str2));
	len = ft_strlen(*str1) + ft_strlen(*str2) + 1;
	temp = (char *)malloc(len * sizeof(char));
	if (temp == NULL)
		return (free(*str1), *str1 = NULL, free(*str2), str2 = NULL, NULL);
	i = -1;
	while ((*str1)[++i])
		temp[i] = (*str1)[i];
	j = -1;
	free(*str1);
	*str1 = NULL;
	while ((*str2)[++j])
		temp[i + j] = (*str2)[j];
	temp[j + i] = '\0';
	return (free(*str2), *str2 = NULL, ft_strdup_g(&*str1, &temp));
}

char	*ft_sub_str(char **dest, char **src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL || !*src)
	{
		return (NULL);
	}
	*dest = (char *)malloc((len - start + 1) * sizeof(char));
	if (*dest == NULL)
	{
		return (NULL);
	}
	while ((*src)[i + start] && i < len)
	{
		(*dest)[i] = (*src)[start + i];
		i++;
	}
	(*dest)[i] = '\0';
	return (*dest);
}

char	*ft_control(char **static_str)
{
	ssize_t	i;
	char	*str;
	char	*res;

	i = 0;
	if (*static_str != NULL)
	{
		if ((*static_str)[0] == '\0')
			return (free(*static_str), *static_str = NULL);
		i = ft_str_chr(*static_str);
		if (i < 0)
			return (ft_strdup_g(&res, static_str), res);
		str = ft_sub_str(&str, &*static_str, i + 1, ft_strlen(*static_str));
		if (str == NULL)
			return (free(*static_str), *static_str = NULL, NULL);
		res = ft_sub_str(&res, static_str, 0, i + 1);
		if (res == NULL)
			return (free(str), free(*static_str), *static_str = NULL);
		free(*static_str);
		*static_str = NULL;
		*static_str = str;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*static_str;
	char			*str_readed;
	ssize_t			count;

	count = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	while (count)
	{
		str_readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (str_readed == NULL)
			return (free(static_str), static_str = NULL, NULL);
		count = read(fd, str_readed, BUFFER_SIZE);
		if (count < 0)
			return (free(str_readed), free(static_str), static_str = NULL);
		if (count > 0)
		{
			str_readed[count] = '\0';
			ft_str_join(&static_str, &str_readed, &count);
		}
		else
			free(str_readed);
	}
	return (ft_control(&static_str));
}
