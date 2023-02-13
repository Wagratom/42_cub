/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 12:40:14 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	open_img_texture(t_data *data, t_img *img, char *path)
{
	if (data->mlx == NULL)
		return (msg_and_error("Error in texture: ", "Pointer mlx NULL"));
	img->img = \
		mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (img->img == NULL)
		return (msg_and_error("Error: can't open the texture: ", path));
	return (TRUE);
}

static t_bool	open_addr_texture(t_img *img)
{
	if (img->img == NULL)
		return (msg_and_error("Error img addr: ", "Pointer img NULL"));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->length, &img->endian);
	if (!img->addr)
		return (msg_and_error("Error: ", "Not get texture addr"));
	return (TRUE);
}

static void	fill_texture(t_img *img, int *texture)
{
	int		i;
	int		j;

	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			texture[img->width * i + j] = img->addr[img->width * i + j];
	}
}

t_bool	load_texture(t_data *data, int *texture, char *path)
{
	t_img	img;

	if (!open_img_texture(data, &img, path))
		return (FALSE);
	if (!open_addr_texture(&img))
		return (FALSE);
	fill_texture(&img, texture);
	mlx_destroy_image(data->mlx, img.img);
	return (TRUE);
}
