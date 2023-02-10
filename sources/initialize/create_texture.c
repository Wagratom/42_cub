/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/10 16:22:34 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	open_img_texture(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (!img->img)
		return (msg_and_error("Error: ", "Not open Texture"));
	return (TRUE);
}

t_bool	open_addr_texture(t_img *img)
{
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
		return (msg_and_error("Error: ", "Not get texture addr"));
	return (TRUE);
}

t_bool	load_texture(t_data *data, int *texture, char *path)
{
	int		i;
	int		j;
	t_img	img;

	if (!open_img_texture(data, &img, path))
		return (FALSE);
	if (!open_addr_texture(&img))
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

t_bool	alloc_texture(t_data *data)
{
	int	index;
	int	size;

	size = sizeof(int) * TILE_SIZE * TILE_SIZE;
	data->texture = (int **)malloc(sizeof(int *) * 4);
	if (!data->texture)
		return (msg_and_error(NULL, "Error: Error in malloc pointer to texture"));
	index = -1;
	while (++index < 4)
	{
		data->texture[index] = (int *)malloc(size);
		if (!data->texture[index])
			return (msg_and_error(NULL, "Error: Error in malloc pointer to texture"));
		ft_bzero(data->texture[index], size); // nao sei c da o msm efeito // pode usar o ft_calloc tb da na mesma
	}
	// texture_zero(data);
	return (TRUE);
}

t_bool	init_texture(t_data *data)
{
	debug_printc(has_flag(), NULL, "allocando a pointers to texture: OK");
	if (!alloc_texture(data))
		return (FALSE);
	if (!load_texture(data, data->texture[NO], "wood.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[SO], "redbrick.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[EA], "greystone.xpm"))
		return (FALSE);
	if (!load_texture(data, data->texture[WE], "colorstone.xpm"))
		return (FALSE);
	debug_printc(has_flag(), NULL, "Texture: Ok\n");
	return (TRUE);
}
