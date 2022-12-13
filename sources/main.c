/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 17:01:50 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	valid_arguments(t_data *data)
{
}


void	start_game(t_data *data)
{
	printf ("			staring game\n good gameplay XD\n");
	draw_map_or_die(data);
	//mlx_hook(data->win, EXIT, 0, &clear_program, data);
	//mlx_hook(data->win, FOCUS, 1L << 21, &draw_map, data);
	//mlx_key_hook(data->win, &filter_keyboard, data);
	mlx_loop(data->mlx);
}


int main(int argc, char *argv[])
{
	t_data	data;

	//valid_arguments();
	init_data(&data);
	valid_map(&data.map);
	init_windows_or_die(&data);
	start_game(&data);
	mlx_loop(data.mlx);
}
