/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 14:04:56 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	get_addr(t_img *img, int *bits, int *length, int *endian)
{
	img->addr = (int *)mlx_get_data_addr(img->img, bits, length, endian);
}

t_bool	get_addr_img(t_img *img)
{
	get_addr(img, &img->bits_per_pixel, &img->length, &img->endian);
	if (img->addr != NULL)
		return (TRUE);
	write(1, "Error: Address not create\n", 23);
	return (FALSE);
}

t_bool	creat_img_status(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.img != NULL)
		return (TRUE);
	write(2, "Error: Image not created\n", 18);
	return (FALSE);
}

t_bool	mlx_is_null(t_data *data)
{
	if (data->mlx != NULL)
		return (FALSE);
	write(2, "Error: Not creat image, Pointer mlx null\n", 34);
	return (TRUE);
}

t_bool	init_img(t_data *data)
{
	if (mlx_is_null(data))
		return (FALSE);
	if (!creat_img_status(data))
		return (FALSE);
	if (!get_addr_img(&data->img))
		return (FALSE);
	debug_printc(has_flag(), "Img: ", "Ok");
	return (TRUE);
}
