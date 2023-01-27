/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/26 18:53:50 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	check_retreat_x(t_map *map, double position_y, double position_x)
{
	double	next_x;

	next_x = position_x - map->dir[P_X] * map->speed;
	if (is_valid_position(map, next_x, map->player[P_Y]) == FALSE)
		return ;
	update_p_player(map, position_y, next_x);
}

static void	check_retreat_y(t_map *map, double position_y, double position_x)
{
	double	next_y;

	next_y = position_y - map->dir[P_Y] * map->speed;
	if (is_valid_position(map, map->player[P_X], next_y) == FALSE)
		return ;
	update_p_player(map, next_y, position_x);
}

void	map_move_down(t_map *map)
{
	check_retreat_x(map, map->player[P_Y], map->player[P_X]);
	check_retreat_y(map, map->player[P_Y], map->player[P_X]);
}
