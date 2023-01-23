/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:33 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	filter_keyboard(int key, t_data *data)
{
	if (key == KEY_ESQ)
		exit(0);
	if (key == KEY_W)
		map_move_up(&data->map);
	else if (key == KEY_D || key == ARROW_RIGHT)
		map_move_right(&data->map);
	else if (key == KEY_S)
		map_move_down(&data->map);
	else if (key == KEY_A || key == ARROW_LEFT)
		map_move_left(&data->map);
	draw_map(data);
	return (0);
}
