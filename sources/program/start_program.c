/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 22:44:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	start_game(t_data *data)
{
	printf ("			staring game\n good gameplay XD\n");
	draw_map_or_die(data);
	//mlx_hook(data->win, EXIT, 0, &clear_program, data);
	//mlx_hook(data->win, FOCUS, 1L << 21, &draw_map, data);
	mlx_key_hook(data->win, &filter_keyboard, data);
	mlx_loop(data->mlx);
}
//10000000W00000001
