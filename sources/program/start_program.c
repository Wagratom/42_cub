/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/06 17:18:07 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	data->player.pos.x = 2;
	data->player.pos.y = 2;
	data->player.dir.x = 0;
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
	mlx_loop_hook(data->mlx, &render, data);
	mlx_key_hook(data->win, &filter_keyboard, data);
}
//10000000W00000001
