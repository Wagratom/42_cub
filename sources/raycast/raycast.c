/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/10 14:06:12 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	texture(t_data *data, t_raycast *r, int j);

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

void	render_background(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT / 2)
			data->t.buf[y][x] = 0x87CEEB;
		y = HEIGHT / 2 - 1;
		while (++y < HEIGHT)
			data->t.buf[y][x] = 0x8B4513;
	}
}

void	raycast(t_data *data)
{
	int			x;
	t_raycast	itens;

	x = -1;
	render_background(data);
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
		texture(data, &itens, x);
		// ver_line(data, &itens, x, RGB_RED);
	}
	// draw(data);
}
