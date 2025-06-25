/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:21:08 by ibondarc          #+#    #+#             */
/*   Updated: 2025/06/25 13:08:34 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error(char *str)
{
	int str_len;
	
	if (!str)
		return ;
	str_len = ft_strlen(str);
	write (2, str, str_len);
}