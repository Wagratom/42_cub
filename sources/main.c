/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:58:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/06 14:33:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	valid_arguments(t_data *data)
{
}

int main(int argc, char *argv[])
{
	t_data	data;

	//valid_arguments();
	init_data(&data);
	valid_map(&data.map);
	init_windows_or_die(&data);
	draw_map_or_die(&data);
	mlx_loop(data.mlx);
}
