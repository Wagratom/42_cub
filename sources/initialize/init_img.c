/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:25 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/05 17:25:49 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static char	*get_addr(t_img *img, int *bits, int *length, int *endian)
{
	img->addr = mlx_get_data_addr(img->img, bits, length, endian);
}

static void	get_addr_img(t_img *img)
{
	get_addr(img,  &img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->addr == NULL)
		printf("Erro in get img addr\n"); //die
}

static void	creat_img(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
		printf("Image not created\n"); //die
}

t_bool	init_img(t_data *data)
{
	if (data->mlx == NULL)
	{
		printf("not create image, Pointer mlx null"); //die
		return (FALSE);
	}
	creat_img(data);
	get_addr_img(&data->img);
	return (TRUE);
}
