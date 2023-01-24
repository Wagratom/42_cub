/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 11:01:33 by wwalas-          ###   ########.fr       */
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

void	check_avance_x(t_map *map, double y, double x)
{
	double	next_x;

	next_x = x + map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, next_x, y) == FALSE)
		return ;
	map->player[P_X] += map->dir[P_X] * map->speed;
}


void	check_avance_Y(t_map *map, double y, double x)
{
	double	next_y;

	next_y =  y + map->dir[P_Y] *map->speed;
	if (is_valid_poosition(map, x, next_y) == FALSE)
		return ;
	map->player[P_Y] += map->dir[P_Y] * map->speed;
}

void	map_move_up(t_map *map)
{

	check_avance_x(map, map->player[P_Y], map->player[P_X]);
	check_avance_Y(map, map->player[P_Y], map->player[P_X]);

}

void	map_move_down(t_map *map)
{
	if (is_valid_poosition(map, map->player[P_X] - map->dir[P_X] * map->speed, map->player[P_Y]))
		map->player[P_X] -= map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, map->player[P_X], map->player[P_Y] - map->dir[P_Y] * map->speed))
		map->player[P_Y] -= map->dir[P_Y] * map->speed;
}

