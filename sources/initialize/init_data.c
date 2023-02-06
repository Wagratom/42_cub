/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 11:22:34 by wwalas-          ###   ########.fr       */
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
		return (write_msg_error("Error: ", "Pointer mlk initializa"));
	debug_printc(has_flag(), "Mlx: ", "Ok");
	return (TRUE);
}

void	set_basic_infos(t_data *data, char *file_name)
{
	data->map.file_name = file_name;
	data->map.speed = 0.15;
	data->map.rot_speed = 0.08;
}

void	init_data(t_data *data, char *file_name)
{
	debug_printc(has_flag(), C, "\tinitializing struct and connections");
	init_struct(data);
	if (!init_mlx_status(data))
		exit_msg(MLX_NULL);
	if (!init_img(data))
		clean_conections(data);
	set_basic_infos(data, file_name);
	debug_printc(has_flag(), NULL, "Sucess createconnections\n");
}
