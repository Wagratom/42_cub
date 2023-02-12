/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:18 by hectfern         ###   ########.fr       */
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

void	render_background(t_data *data, int c, int f)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT / 2)
			data->t.buf[y][x] = c;
		y = HEIGHT / 2 - 1;
		while (++y < HEIGHT)
			data->t.buf[y][x] = f;
	}
}

void	raycast(t_data *data)
{
	int			x;
	t_raycast	itens;

	x = -1;
	render_background(data, data->map.c, data->map.f);
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
	}
}
