/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/23 16:07:37 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	map_move_right(t_map *map)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = map->dir[P_X];
	map->dir[P_X] = map->dir[P_X] * cos(-map->rot_speed) - map->dir[P_Y] * sin(-map->rot_speed);
	map->dir[P_Y] = old_dir_x * sin(-map->rot_speed) + map->dir[P_Y] * cos(-map->rot_speed);
	old_plane_x = map->plane[P_X];
	map->plane[P_X] = map->plane[P_X] * cos(-map->rot_speed) - map->plane[P_Y] * sin(-map->rot_speed);
	map->plane[P_Y] = old_plane_x * sin(-map->rot_speed) + map->plane[P_Y] * cos(-map->rot_speed);

}

void	map_move_left(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = map->dir[P_X];
	map->dir[P_X] = map->dir[P_X] * cos(map->rot_speed) - map->dir[P_Y] * sin(map->rot_speed);
	map->dir[P_Y] = old_dir_x * sin(map->rot_speed) + map->dir[P_Y] * cos(map->rot_speed);
	old_plane_x = map->plane[P_X];
	map->plane[P_X] = map->plane[P_X] * cos(map->rot_speed) - map->plane[P_Y] * sin(map->rot_speed);
	map->plane[P_Y] = old_plane_x * sin(map->rot_speed) + map->plane[P_Y] * cos(map->rot_speed);
}
