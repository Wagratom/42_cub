/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 22:25:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	update_p_char(t_map *map, int x, int y)
{
	map->map[y][x] = 'W';
}

void	update_p_player(t_map *map, int position_x, int position_y)
{
	map->p_player[P_X] = position_x;
	map->p_player[P_Y] = position_y;
}
