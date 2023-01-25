/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 17:37:20 by wwalas-          ###   ########.fr       */
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
		my_mlx_pixel_put(&data->img, x, y1, color);
}

void	nao_sei_oq_ta_acontecendo(t_raycast *itens, t_data *data)
{
	double	aux;

	aux = itens->map[P_X] - player_p_x(data) + (1 - itens->step[P_X]) / 2;
	if (itens->side == 0)
		itens->perpWallDist = aux / itens->rayDir[P_X];
	else
	{
		aux = itens->map[P_Y] - player_p_y(data) + (1 - itens->step[P_Y]) / 2;
		itens->perpWallDist = aux / itens->rayDir[P_Y];
	}
}

void	lance_ray_in_wall(t_raycast *itens, t_data *data)
{
	while (TRUE)
	{
		if (itens->sideDist[P_X] < itens->sideDist[P_Y])
		{
			itens->sideDist[P_X] += itens->deltaDist[P_X];
			itens->map[P_X] += itens->step[P_X];
			itens->side = 0;
		}
		else
		{
			itens->sideDist[P_Y] += itens->deltaDist[P_Y];
			itens->map[P_Y] += itens->step[P_Y];
			itens->side = 1;
		}
		print_larger_pixel(data, itens->map[P_X] * 5, \
		itens->map[P_Y] * 5, RGB_RED);
		if (data->map.map[itens->map[P_Y]][itens->map[P_X]] == '1')
			return ;
	}
}

void	jump_next_square_and_verify_hit_wall(t_raycast *itens, t_data *data)
{
	lance_ray_in_wall(itens, data);
	nao_sei_oq_ta_acontecendo(itens, data);
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
		calculate_height_line(&itens, data);
		calculate_pixel(&itens, data);
		ver_line(data, &itens, x, RGB_RED);
	}
}
