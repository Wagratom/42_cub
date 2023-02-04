/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:11 by hectfern         ###   ########.fr       */
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

t_bool	init_texture(t_data *data)
{
	int		i;
	int		j;
	t_img	img;
	
	img.img = mlx_xpm_file_to_image(data->mlx, "redbrick.xpm", &img.width, &img.height);
	if (!img.img)
		return (FALSE);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data->texture = (int *)(malloc(sizeof(int) * (TILE_SIZE * TILE_SIZE)));
	if (!data->texture || !img.addr)
		return (FALSE);
	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
		data->texture[i] = 0;
	i = -1;
	while (++i < img.height)
	{
		j = -1;
		while (++j < img.width)
			data->texture[img.width * i + j] = img.addr[img.width * i + j];
	}
	mlx_destroy_image(data->mlx, img.img);
}

void	init_data(t_data *data, char *file_name)
{
	debug_print(has_flag(), "\tinitializing struct and connections\n");
	init_struct(data);
	if (init_mlx_or_die(data) == FALSE)
		exit_msg(MLX_NULL);
	if (init_texture(data) == FALSE)
		exit_msg("deu ruim na textura\n");
	if (init_img(data) == FALSE)
		clean_conections(data);
	debug_print(has_flag(), "Sucess: Create Connections\n\n");
	data->map.file_name = file_name;
	data->map.dir[P_X] = 0;
	data->map.dir[P_Y] = 0;
	data->map.plane[P_X] = 0;
	data->map.plane[P_Y] = 0;
	data->map.speed = 0.15;
	data->map.rot_speed = 0.08;
	data->t.flag = 0;
}
