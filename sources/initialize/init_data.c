/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/23 15:35:15 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_struct(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
}

void	init_data(t_data *data, char *file_name)
{
	init_struct(data);
	init_mlx_or_die(data);
	init_img(data);
	data->map.file_name = file_name;
	data->map.dir[P_X] = -1;
	data->map.dir[P_Y] = 0;
	data->map.plane[P_X] = 0;
	data->map.plane[P_Y] = 0.66;
	data->map.speed = 0.5;
	data->map.rot_speed = 0.1;
}
