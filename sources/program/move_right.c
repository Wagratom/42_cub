/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/26 19:27:48 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	map_move_right(t_map *map)
{
	if (map->map[(int)map->player[P_Y]]
	[(int)(map->player[P_X] + map->dir[P_Y] * map->speed)] == '0')
		map->player[P_X] += map->dir[P_Y] * map->speed;
	if (map->map[(int)(map->player[P_Y] - map->dir[P_X] * map->speed)]
	[(int)(map->player[P_X])] == '0')
		map->player[P_Y] -= map->dir[P_X] * map->speed;
}