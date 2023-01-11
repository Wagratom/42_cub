/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/06 16:26:42 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_position(t_map *map, long x, long y)
{
	int	x_;
	int	y_;

	x_ = (int)x;
	y_ = (int)y;
	if (map->map[y_][x_] == '1')
		return (TRUE);
	return (TRUE);
}

int	move_up(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (check_position(map, data->player.pos.x + \
		data->player.dir.x * data->player.speed, data->player.pos.y))
		data->player.pos.x += data->player.dir.x * data->player.speed;
	return (0);
}

int	move_down(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (check_position(map, data->player.pos.x - \
		data->player.dir.x * data->player.speed, data->player.pos.y))
		data->player.pos.x -= data->player.dir.x * data->player.speed;
	return (0);
}

int look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(data->player.rot_speed) - \
		data->player.dir.y * sin(data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(data->player.rot_speed) + \
		data->player.dir.y * cos(data->player.rot_speed);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(data->player.rot_speed) \
		- data->player.plane.y * sin(data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(data->player.rot_speed) + \
		data->player.plane.y * cos(data->player.rot_speed);
	return (0);
}

int	look_right(t_data *data)
{
	double		old_dir_x;
	double		old_plane_x;
	t_player	*player;

	player = &data->player;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed) - \
		player->dir.y * sin(-player->rot_speed);
	player->dir.y = old_dir_x * sin(-player->rot_speed) + \
		player->dir.y * cos(-player->rot_speed);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(-player->rot_speed) - \
		player->plane.y * sin(-player->rot_speed);
	player->plane.y = old_plane_x * sin(-player->rot_speed) + \
		player->plane.y * cos(-player->rot_speed);
	return (0);
}

int	filter_keyboard(int key, t_data *data)
{
	if (key == KEY_ESQ)
		exit (0);
		// clear_program(data);
	if (key == KEY_W)
		move_up(data);
		// map_move_up(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_D)
		look_right(data);
	// 	map_move_right(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_S)
		move_down(data);
	// 	map_move_down(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_A)
		look_left(data);
	// 	map_move_left(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	// else if (key == ARROW_UP)
	// {
	// 	if (data->map->dir[P_Y] - 1 >= 0)
	// 		data->map->dir[P_Y] -= 1;
	// }
	// else if (key == ARROW_RIGHT)
	// 	data->map.dir[P_X] += 1;
	// else if (key == ARROW_DOWN)
	// 	data->map.dir[P_Y] += 1;
	// else if (key == ARROW_LEFT)
	// {
	// 	if (data->map.dir[P_X] - 1 >= 0)
	// 		data->map.dir[P_X] -= 1;
	// }
	// draw_map(data);
	// draw_map_debug(data->map.map);
	return (0);
}
