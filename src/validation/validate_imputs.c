/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_imputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:00:49 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:14:41 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void validate_imputs(t_game *game, int ac, char *str)
{
    int     len;
    
    (void)str;
    (void)ac;
    //  "../../assets/maps/invalid_map.cub"
    if (ac != 2)
        exit_with_error(NULL, FD);
    len = ft_strlen(str);
    if (ft_strcmp(&str[len - 4], ".cub") != 0) //  || ft_strcmp(str, ".cub") == 0
        exit_with_error(NULL, WN);
    if (len < 5 || !ft_strcmp(&str[len - 5], "/.cub"))
        exit_with_error(NULL, TSN);
    game->fd = open(str, O_RDONLY);
    if (game->fd < 0)
         exit_with_error(NULL, NVP);
}
