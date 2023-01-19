/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/19 15:36:02 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//direita     0 1
//meio baixo  1 1
//esquerda  0 1

void	start_game(t_data *data)
{
	data->player.pos.x = 4;
	data->player.pos.y = 4;
	//printf("%c\n", data->map.map[(int)data->player.pos.y][(int)data->player.pos.x]);
	data->player.dir.x = 1;
	data->player.dir.y = 1;
	data->player.plane.x = 0.66;
	data->player.plane.y = 0;
	data->player.speed = 0.5;
	data->player.rot_speed = 0.1;
	data->ray.pos.x = 0;
	data->ray.pos.y = 0;

	// printf ("			staring game\n good gameplay XD\n");
	// draw_map_or_die(data);
	//mlx_hook(data->win, EXIT, 0, &clear_program, data);
	//mlx_hook(data->win, FOCUS, 1L << 21, &draw_map, data);
	render(data);
	//mlx_loop_hook(data->mlx, &render, data);
	mlx_key_hook(data->win, &filter_keyboard, data);
}
//10000000W00000001
