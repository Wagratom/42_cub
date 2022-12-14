/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 20:32:30 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	map_move_up(t_map *map, int x, int y)
{
	if (map->map[y - 1][x] == '1')
		return ;
	map->map[y][x] = '0';
	update_p_char(map, x, (y - 1));
	update_p_player(map, x, (y - 1));
}

void	map_move_right(t_map *map, int x, int y)
{
	if (map->map[y][x + 1] == '1')
		return ;
	map->map[y][x] = '0';
	update_p_char(map, (x + 1), y);
	update_p_player(map, (x + 1), y);
}

void	map_move_left(t_map *map, int x, int y)
{
	if (map->map[y][x - 1] == '1')
		return ;
	map->map[y][x] = '0';
	update_p_char(map, (x - 1), y);
	update_p_player(map, (x - 1), y);
}

void	map_move_down(t_map *map, int x, int y)
{
	if (map->map[y + 1][x] == '1')
		return ;
	map->map[y][x] = '0';
	update_p_char(map, x, (y + 1));
	update_p_player(map, x, (y + 1));
}

