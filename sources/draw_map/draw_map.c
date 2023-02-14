/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 21:43:40 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
			data->img.addr[x * WIDTH + y] = data->t.buf[x][y];
	}
}

t_bool	draw_map_status(t_data *data)
{
	if (data->map.mini_map == NULL)
		return (msg_and_error(NULL, "can't draw the map, map doesn't exist"));
	draw_map(data);
	return (TRUE);
}

int	draw_map(t_data *data)
{
	raycast(data);
	draw(data);
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
