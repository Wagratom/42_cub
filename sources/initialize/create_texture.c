/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 13:41:25 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	open_img_texture(t_data *data, t_img *img, char *path)
{
	if (data->mlx == NULL)
		return (msg_and_error("Error in opening texture: ", "Pointer mlx NULL"));
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (img->img == NULL)
		return (msg_and_error("Error: can't open the texture: ", path));
	return (TRUE);
}

t_bool	open_addr_texture(t_img *img)
{
	if (img->img == NULL)
		return (msg_and_error("Error in getting img addr: ", "Pointer img NULL"));
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

t_bool	alloc_texture(t_map *data)
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
	return (TRUE);
}

static t_bool	clear_texture(t_map *data)
{
	int	index;

	index = -1;
	while(++index < 4)
		free(data->texture[index]);
	free(data->texture);
	return (FALSE);
}

t_bool	init_texture(t_data *data)
{
	int	index;
	t_map	*map;

	debug_printc(has_flag(), NULL, "allocando a pointers to texture: OK");
	map = &data->map;
	if (!alloc_texture(map))
		return (FALSE);
	index = -1;
	while (++index < 4)
	{
		if (load_texture(data, map->texture[index], data->parser.coordinates[index]))
			continue;
		clear_texture(map);
		return (msg_and_error("Error: ", "Not load texture"));
	}
	debug_printc(has_flag(), NULL, "Texture: Ok\n");
	return (TRUE);
}
