/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/19 13:38:41 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_position(t_map *map, double x, double y)
{
	printf("x = %f | y = %f | map: %c\n", x, y, map->map[(int)x][(int)y]);
	if (map->map[(int)x][(int)y] == '1')
		return (TRUE);
	return (FALSE);
}

int	move_up(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (check_position(map, data->player.pos.x + \
		data->player.dir.x * data->player.speed, data->player.pos.y))
		data->player.pos.x += data->player.dir.x * data->player.speed;
	if (check_position(map, data->player.pos.x, data->player.pos.y + \
		data->player.dir.y * data->player.speed))
		data->player.pos.y += data->player.dir.y * data->player.speed;
	return (0);
}

int	move_down(t_data *data)
{
	t_map	*map;

	map = &data->map;
	if (check_position(map, data->player.pos.x - \
		data->player.dir.x * data->player.speed, data->player.pos.y))
		data->player.pos.x -= data->player.dir.x * data->player.speed;
	if (check_position(map, data->player.pos.x, data->player.pos.y - \
		data->player.dir.y * data->player.speed))
		data->player.pos.y -= data->player.dir.y * data->player.speed;
	return (0);
}

int look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	printf("1 - dir.x = %f | dir.y = %f\n", data->player.dir.x, data->player.dir.y);
	data->player.dir.x = data->player.dir.x * cos(data->player.rot_speed) - \
		data->player.dir.y * sin(data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(data->player.rot_speed) + \
		data->player.dir.y * cos(data->player.rot_speed);
	printf("2 - dir.x = %f | dir.y = %f\n", data->player.dir.x, data->player.dir.y);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(data->player.rot_speed) \
		- data->player.plane.y * sin(data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(data->player.rot_speed) + \
		data->player.plane.y * cos(data->player.rot_speed);
	printf("3 - plane.x = %f | plane.y = %f\n", data->player.plane.x, data->player.plane.y);
	printf("pos.x = %f | pos.y = %f\n", data->player.pos.x, data->player.pos.y);
	return (0);
}

int	look_right(t_data *data)
{
	double		old_dir_x;
	double		old_plane_x;
	t_player	*player;

	player = &data->player;
	printf("1 - dir.x = %f | dir.y = %f\n", data->player.dir.x, data->player.dir.y);
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed) - \
		player->dir.y * sin(-player->rot_speed);
	player->dir.y = old_dir_x * sin(-player->rot_speed) + \
		player->dir.y * cos(-player->rot_speed);
	old_plane_x = player->plane.x;
	printf("2 - dir.x = %f | dir.y = %f\n", data->player.dir.x, data->player.dir.y);
	player->plane.x = player->plane.x * cos(-player->rot_speed) - \
		player->plane.y * sin(-player->rot_speed);
	player->plane.y = old_plane_x * sin(-player->rot_speed) + \
		player->plane.y * cos(-player->rot_speed);
	printf("3 - plane.x = %f | plane.y = %f\n", data->player.plane.x, data->player.plane.y);
	printf("pos.x = %f | pos.y = %f\n", data->player.pos.x, data->player.pos.y);
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
