/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/10 13:59:35 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	debug_printc(has_flag(), G, "\tstaring game");
	draw_map_status(data);
	mlx_hook(data->win, EXIT, 0, &cleanup_program, data);
	mlx_hook(data->win, PRESS_KEY, (1L << 0), &filter_keyboard, data);
	mlx_loop(data->mlx);
}
