/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 12:13:57 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	map_move_down(t_map *map)
{
	if (is_valid_poosition(map, map->player[P_X] - map->dir[P_X] * map->speed, map->player[P_Y]))
		map->player[P_X] -= map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, map->player[P_X], map->player[P_Y] - map->dir[P_Y] * map->speed))
		map->player[P_Y] -= map->dir[P_Y] * map->speed;
}

