/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 17:42:21 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	printf ("			staring game\n good gameplay XD\n");
	draw_map_or_die(data);
	mlx_hook(data->win, EXIT, 0, &cleanup_program, data);
	mlx_hook(data->win, PRESS_KEY, (1L << 0), &filter_keyboard, data);
	mlx_loop(data->mlx);
}
