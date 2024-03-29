/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 10:10:59 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	debug_printc(has_flag(), G, "\tstaring game");
	draw_map_status(data);
	mlx_hook(data->win, EXIT, 0, &cleanup_program, data);
	mlx_hook(data->win, PRESS_KEY, (1L << 0), &filter_keyboard, data);
	mlx_hook(data->win, FOCUS, 1L << 21, &draw_map, data);
	mlx_expose_hook(data->win, &draw_map, data);
	mlx_loop(data->mlx);
}
