/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/10 13:08:51 by wwalas-          ###   ########.fr       */
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

t_bool	load_texture(t_data *data, int *texture, char *path)
{
	int		i;
	int		j;
	t_img	img;

	img.img = mlx_xpm_file_to_image(data->mlx, path, &img.width, &img.height);
	if (!img.img)
		return (FALSE);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	if (!img.addr)
		return (FALSE);
	i = -1;
	while (++i < img.height)
	{
		j = -1;
		while (++j < img.width)
			texture[img.width * i + j] = img.addr[img.width * i + j];
	}
	mlx_destroy_image(data->mlx, img.img);
	return (TRUE);
}

void	texture_zero(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TILE_SIZE * TILE_SIZE)
	{
		data->texture[NO][i] = 0;
		data->texture[SO][i] = 0;
		data->texture[EA][i] = 0;
		data->texture[WE][i] = 0;
	}
}

t_bool	init_texture(t_data *data)
{
	int	i;

	data->texture = (int **)malloc(sizeof(int *) * 4);
	if (!data->texture)
		return (FALSE);
	i = -1;
	while (++i < 4)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * TILE_SIZE * TILE_SIZE);
		if (!data->texture[i])
			return (FALSE);
	}
	texture_zero(data);
	if (!load_texture(data, data->texture[NO], "wood.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[SO], "redbrick.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[EA], "greystone.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[WE], "colorstone.xpm"))
		return (FALSE);
	debug_print(has_flag(), "Texture: Ok\n");
	return (TRUE);
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
	set_basic_infos(data, file_name);
	if (!init_mlx_status(data))
		exit_msg(MLX_NULL);
	if (!init_img(data))
		clean_conections(data);
	if (init_texture(data) == FALSE)
		exit_msg("deu ruim na textura\n");
	data->map.file_name = file_name;
	data->map.dir[P_X] = 0;
	data->map.dir[P_Y] = 0;
	data->map.plane[P_X] = 0;
	data->map.plane[P_Y] = 0;
	data->map.speed = 0.09;
	data->map.rot_speed = 0.08;
	data->t.flag = 0;
	debug_printc(has_flag(), NULL, "Sucess createconnections\n");
}
