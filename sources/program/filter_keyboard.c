/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/26 13:29:09 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	filter_keyboard(int key, t_data *data)
{
	if (key == KEY_ESQ)
		exit(0);
	if (key == KEY_W)
		map_move_up(&data->map);
	else if (key == KEY_D)
		map_move_right(&data->map);
	else if (key == ARROW_RIGHT)
		map_look_right(&data->map);
	else if (key == KEY_S)
		map_move_down(&data->map);
	else if (key == KEY_A)
		map_move_left(&data->map);
	else if (key == ARROW_LEFT)
		map_look_left(&data->map);
	draw_map(data);
	return (0);
}
