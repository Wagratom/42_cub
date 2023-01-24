/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 12:47:05 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	check_avance_x(t_map *map, double position_y, double position_x)
{
	double	next_x;

	next_x = position_x + map->dir[P_X] * map->speed;
	if (is_valid_poosition(map, next_x, position_y) == FALSE)
		return ;
	update_p_player(map, position_y, next_x);
}

static void	check_avance_y(t_map *map, double position_y, double position_x)
{
	double	next_y;

	next_y =  position_y + map->dir[P_Y] *map->speed;
	if (is_valid_poosition(map, position_x, next_y) == FALSE)
		return ;
	update_p_player(map, next_y, position_x);
}

void	map_move_up(t_map *map)
{
	check_avance_x(map, map->player[P_Y], map->player[P_X]);
	check_avance_y(map, map->player[P_Y], map->player[P_X]);
}

