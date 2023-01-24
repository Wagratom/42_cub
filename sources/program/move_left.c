/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 14:16:21 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	set_cos_and_sin_left(double *ptr_cos, double *ptr_sin, double rotation)
{
	*ptr_cos = cos(rotation);
	*ptr_sin = sin(rotation);
}

static void	update_dir_left(t_map *map, double dir[])
{
	double	old_dir_x;
	double	cos_rotation;
	double	sin_rotation;

	old_dir_x = dir[P_X];
	set_cos_and_sin_left(&cos_rotation, &sin_rotation, map->rot_speed);
	dir[P_X] = dir[P_X] * cos_rotation - dir[P_Y] * sin_rotation;
	dir[P_Y] = old_dir_x * sin_rotation + dir[P_Y] * cos_rotation;
}

static void	update_plane_left(t_map *map, double plane[])
{
	double	old_plane_x;
	double	cos_rotation;
	double	sin_rotation;

	old_plane_x = plane[P_X];
	set_cos_and_sin_left(&cos_rotation, &sin_rotation, map->rot_speed);
	plane[P_X] = plane[P_X] * cos_rotation - plane[P_Y] * sin_rotation;
	plane[P_Y] = old_plane_x * sin_rotation + plane[P_Y] * cos_rotation;
}

void	map_move_left(t_map *map)
{
	update_dir_left(map, map->dir);
	update_plane_left(map, map->plane);
}
