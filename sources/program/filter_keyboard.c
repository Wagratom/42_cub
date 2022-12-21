/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/21 11:24:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	filter_keyboard(int key, t_data *data)
{
	if (key == KEY_ESQ)
		exit(0);
	if (key == KEY_W)
		map_move_up(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_D)
		map_move_right(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_S)
		map_move_down(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	else if (key == KEY_A)
		map_move_left(&data->map, data->map.p_player[P_X], data->map.p_player[P_Y]);
	draw_map(data);
	return (0);
}
