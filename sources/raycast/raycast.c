/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 14:30:42 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_raycast(t_raycast *itens, t_data *data)
{
	ft_bzero(itens, sizeof(t_raycast));
	itens->dir[P_X] = data->map.dir[P_X];		//initial direction vector
	itens->dir[P_Y] = data->map.dir[P_Y];

	itens->plane[P_X] = data->map.plane[P_X];
	itens->plane[P_Y] = data->map.plane[P_Y];
}

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	y1--;
	while (++y1 <= y2)
		my_mlx_pixel_put(&data->img, x, y1, color);
}

void	jump_next_square_and_verify_hit_wall(t_raycast * itens, t_data *data, int hit)
{
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
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
		//Check if ray has hit a wall
		print_larger_pixel(data, itens->map[P_X] * 5, itens->map[P_Y] * 5, RGB_RED);
		if (data->map.map[itens->map[P_Y]][itens->map[P_X]] == '1') hit = 1;
	}
	if (itens->side == 0)
		itens->perpWallDist = (itens->map[P_X] - player_posX(data) + (1 - itens->step[P_X]) / 2) / itens->rayDir[P_X];
	else
		itens->perpWallDist = (itens->map[P_Y] - player_posY(data) + (1 - itens->step[P_Y]) / 2) / itens->rayDir[P_Y];
}

void	raycast(t_data *data)
{
	t_raycast	itens;

	init_raycast(&itens, data);
	for (int x = 0; x < 640; x++)
   	{
		calculate_ray_position_direction(&itens, x);
		position_player_map(&itens, data);
		lengthRay(&itens);
		lengthRayNext_x_y(&itens, data);
		jump_next_square_and_verify_hit_wall(&itens, data, 0);
		calculateHeightLinen(&itens, data);
		calculatePixel(&itens, data);
		verLine(data, x, itens.drawStart, itens.drawEnd, RGB_RED);
	}
}
