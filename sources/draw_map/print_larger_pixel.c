/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_larger_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:38:49 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/10 13:07:45 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(t_img *img, int y, int x, int color)
{
	char	*dst;

	dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_larger_pixel(t_data *data, int y, int x, int color)
{
	int	len_x;
	int	size_y;

	save_value_x(x);
	len_x = get_save_x() + 5;
	size_y = get_size_y(y);
	while (y++ < size_y - 1)
	{
		x = get_save_x();
		while (x++ < len_x - 1)
			my_mlx_pixel_put(&data->img, y, x, color);
	}
	save_value_x(0);
}
