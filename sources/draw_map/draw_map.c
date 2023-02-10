/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/09 22:34:49 by hectfern         ###   ########.fr       */
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

int	draw_map(t_data *data)
{
	raycast(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	draw_map_or_die(t_data *data)
{
	if (data->map.map == NULL)
	{
		printf("can't draw the map, map doesn't exist");
		return (FALSE);
	}
	return (draw_map(data));
}
