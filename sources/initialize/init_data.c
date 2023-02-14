/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 22:32:18 by wwalas-          ###   ########.fr       */
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
		return (msg_and_error("Error: ", "Pointer mlk initializa"));
	debug_printc(has_flag(), "Mlx: ", "Ok");
	return (TRUE);
}

void	set_basic_infos(t_data *data, char *file_name)
{
	data->map.file_name = file_name;
	data->map.speed = 0.09;
	data->map.rot_speed = 0.08;
	data->parser.f[0] = -1;
	data->parser.c[0] = -1;
	data->map.player[0] = -1;
}

void	init_data_or_die(t_data *data, char *file_name)
{
	debug_printc(has_flag(), C, "\tinitializing struct and connections");
	init_struct(data);
	set_basic_infos(data, file_name);
	if (!init_mlx_status(data))
		exit_msg(MLX_NULL);
	if (!init_img(data))
		clean_connections(data);
	debug_printc(has_flag(), NULL, "Sucess createconnections\n");
}
