/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 17:52:13 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_raycast(t_raycast *itens, t_data *data)
{
	ft_bzero(itens, sizeof(t_raycast));
	itens->dir[P_X] = data->map.dir[P_X];
	itens->dir[P_Y] = data->map.dir[P_Y];
	itens->plane[P_X] = data->map.plane[P_X];
	itens->plane[P_Y] = data->map.plane[P_Y];
}

void	ver_line(t_data *data, t_raycast *itens, int x, int color)
{
	int	y1;
	int	y2;

	y1 = itens->drawStart - 1;
	y2 = itens->drawEnd;
	while (++y1 <= y2)
		my_mlx_pixel_put(&data->img, y1, x, color);
}

void	raycast(t_data *data)
{
	t_raycast	itens;
	int			x;

	x = -1;
	init_raycast(&itens, data);
	while (++x < WIDTH)
	{
		calculate_ray_position_direction(&itens, x);
		position_player_map(&itens, data);
		length_ray(&itens);
		length_ray_next_x_y(&itens, data);
		jump_next_square_and_verify_hit_wall(&itens, data);
		calculate_height_line(&itens);
		calculate_pixel(&itens);
		ver_line(data, &itens, x, RED);
	}
}
