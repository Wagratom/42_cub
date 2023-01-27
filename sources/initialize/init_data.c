/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:09:41 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_struct(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	debug_print(has_flag(), "Struct: Ok\n");
}

t_bool	init_mlx_or_die(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FALSE);
	debug_print(has_flag(), "Mlx: Ok\n");
	return (TRUE);
}

void	init_data(t_data *data, char *file_name)
{
	debug_print(has_flag(), "\tinitializing struct and connections\n");
	init_struct(data);
	if (init_mlx_or_die(data) == FALSE)
		exit_msg(MLX_NULL);
	if (init_img(data) == FALSE)
		clean_conections(data);
	debug_print(has_flag(), "Sucess: Create Connections\n\n");
	data->map.file_name = file_name;
	data->map.dir[P_X] = -1;
	data->map.dir[P_Y] = 0;
	data->map.plane[P_X] = 0;
	data->map.plane[P_Y] = 0.66;
	data->map.speed = 0.15;
	data->map.rot_speed = 0.08;
}
