/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:08:51 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static char	*get_addr(t_img *img, int *bits, int *length, int *endian)
{
	img->addr = mlx_get_data_addr(img->img, bits, length, endian);
}

t_bool	get_addr_img(t_img *img)
{
	get_addr(img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->addr != NULL)
		return (TRUE);
	write(1, "Error: Address not create\n", 23);
	return (FALSE);
}

t_bool	creat_img_status(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, 640, 480);
	if (data->img.img != NULL)
		return (TRUE);
	write(2, "Error: Image not created\n", 18);
	return (FALSE);
}

t_bool mlx_is_null(void	*mlx)
{
	if (mlx == NULL)
	{
		write(2, "Error: Not creat image, Pointer mlx null\n", 34);
		return (FALSE);
	}
}

t_bool	init_img(t_data *data)
{
	if (mlx_is_null(data->mlx) == TRUE)
		return (FALSE);
	if (creat_img_status(data) == FALSE)
		return (FALSE);
	if (get_addr_img(&data->img) == FALSE)
		return (FALSE);
	debug_print(has_flag(), "Img: Ok\n");
	return (TRUE);
}
