/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/05 16:08:53 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_struct(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	debug_printc(has_flag(), "Struct: ", "Ok");
}

t_bool	init_mlx_status(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FALSE);
	debug_printc(has_flag(), "Mlx: ", "Ok");
	return (TRUE);
}

void	init_data(t_data *data, char *file_name)
{
	debug_printc(has_flag(), C, "\tinitializing struct and connections");
	init_struct(data);
	if (!init_mlx_status(data))
		exit_msg(MLX_NULL);
	if (!init_img(data))
		clean_conections(data);
	debug_printc(has_flag(), NULL, "Sucess createconnections\n");
	data->map.file_name = file_name;
	data->map.dir[P_X] = 0;
	data->map.dir[P_Y] = 0;
	data->map.plane[P_X] = 0;
	data->map.plane[P_Y] = 0;
	data->map.speed = 0.15;
	data->map.rot_speed = 0.08;
}
