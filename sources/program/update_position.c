/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 10:44:35 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_valid_poosition(t_map *map, double x, double y)
{
	// printf("printei\nx = %d y = %d\n", (int)x, (int)y);

	if (map->map[(int)y][(int)x] == '1')
		return (FALSE);
	return (TRUE);
}

void	map_move_up(t_map *map)
{
	// printf("\nmove speed = %f\n", map->speed);
	// printf("dirX = %f playX = %f\n", map->dir[P_X], map->player[P_X]);
	// printf("\nresult = %f\n", map->player[P_X] + map->dir[P_X] * map->speed);

	if (is_valid_poosition(map, map->player[P_X] + map->dir[P_X] * map->speed, map->player[P_Y]))
		map->player[P_X] += map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, map->player[P_X], map->player[P_Y] + map->dir[P_Y] *map->speed))
		map->player[P_Y] += map->dir[P_Y] * map->speed;
}

void	map_move_down(t_map *map)
{
	if (is_valid_poosition(map, map->player[P_X] - map->dir[P_X] * map->speed, map->player[P_Y]))
		map->player[P_X] -= map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, map->player[P_X], map->player[P_Y] - map->dir[P_Y] * map->speed))
		map->player[P_Y] -= map->dir[P_Y] * map->speed;
}

