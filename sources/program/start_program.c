/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 12:27:32 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	printf ("			staring game\n good gameplay XD\n");
	draw_map_or_die(data);
	// mlx_loop_hook(data->mlx, &draw_map_or_die, data);
	mlx_hook(data->win, EXIT, 0, &cleanup_program, data);
	mlx_hook(data->win, PRESS_KEY, (1L << 0), &filter_keyboard, data);
	mlx_loop(data->mlx);
}
