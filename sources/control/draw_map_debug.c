/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/05 23:18:41 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_mapingd(char **map)
{
	if (!has_flag())
		return ;
	if (map == NULL)
		return ;
	write(1, B, ft_strlen(B));
	write(1, "\tMap\n", 5);
	write(1, BKB, ft_strlen(BKB));
	while (*map)
	{
		write(1, *map, ft_strlen(*map));
		map++;
	}
	write(1, W, ft_strlen(W));
	write(1, "\n", 1);
}
