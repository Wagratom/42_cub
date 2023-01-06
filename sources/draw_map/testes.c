/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/06 13:58:36 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <math.h>

void	print_larger_pixel_tst(t_data *data, int x, int y, int color)
{
	int			len_x;
	int			size_y;

	save_value_x(x);
	len_x = get_save_x() + 3;
	size_y = y + 3;
	while (y++ < size_y)
	{
		x = get_save_x();
		while (x++ < len_x)
			my_mlx_pixel_put(&data->img, x, y, color);
	}
	save_value_x(0);
}

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		my_mlx_pixel_put(&data->img, x, y, color);
		y++;
	}
}

void	init_raycast(t_raycast *itens)
{
	ft_bzero(itens, sizeof(t_raycast));
	itens->dir[P_X] = -1;		//initial direction vector
	itens->dir[P_Y] =  0;

	itens->plane[P_X] = 0;
	itens->plane[P_Y] = 0.66;
}

void	calculate_ray_position_direction(t_raycast *itens, t_data *data, int x)
{
	itens->cameraX = 2 * x / (double)640 - 1;				//x-coordinate in camera space
	itens->rayDir[P_X] = itens->dir[P_X] + itens->plane[P_X] * itens->cameraX;
	itens->rayDir[P_Y] = itens->dir[P_Y] + itens->plane[P_Y] * itens->cameraX;
}

// which box of the map we're in
void	position_player_map(t_raycast *itens, t_data *data)
{
	itens->map[P_X] = (int)player_posX(data);
	itens->map[P_Y] = (int)player_posY(data);
}

void	length_of_ray_from_current_position_to_next_x_or_y_side(t_raycast *itens)
{
	itens->deltaDist[P_X] = fabs(1 / itens->rayDir[P_X]);
	itens->deltaDist[P_Y] = fabs(1 / itens->rayDir[P_Y]);
}

void	side_x(t_raycast * itens, t_data *data)
{
	if (itens->rayDir[P_X] < 0)
	{
		itens->step[P_X] = -1;
		itens->sideDist[P_X] = (player_posX(data) - itens->map[P_X]) * itens->deltaDist[P_X];
	}
	else
	{
		itens->step[P_X] = 1;
		itens->sideDist[P_X] = (itens->map[P_X] + 1.0 - player_posX(data)) * itens->deltaDist[P_X];
	}
}

void	side_y(t_raycast * itens, t_data *data)
{
	if (itens->rayDir[P_Y] < 0)
	{
		itens->step[P_Y] = -1;
		itens->sideDist[P_Y] = (player_posY(data) - itens->map[P_Y]) * itens->deltaDist[P_Y];
	}
	else
	{
		itens->step[P_Y] = 1;
		itens->sideDist[P_Y] = (itens->map[P_Y] + 1.0 - player_posY(data)) * itens->deltaDist[P_Y];
	}
}

void	length_of_ray_from_one_x_or_y_side_to_next_x_or_y_side(t_raycast *itens, t_data *data)
{
	side_x(itens, data);
	side_y(itens, data);
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
		print_larger_pixel_tst(data, itens->map[P_X] * 5, itens->map[P_Y] * 5, RGB_RED);
		if (data->map.map[itens->map[P_Y]][itens->map[P_X]] == '1') hit = 1;
	}
	if (itens->side == 0)
		itens->perpWallDist = (itens->map[P_X] - player_posX(data) + (1 - itens->step[P_X]) / 2) / itens->rayDir[P_X];
	else
		itens->perpWallDist = (itens->map[P_Y] - player_posY(data) + (1 - itens->step[P_Y]) / 2) / itens->rayDir[P_Y];
}

void	calculate_height_of_line_to_draw_on_screen(t_raycast *itens, t_data *data)
{
	itens->lineHeight = (int)(480 / itens->perpWallDist);
	itens->drawStart = - itens->lineHeight / 2 + 480 / 2;
}

void	calculate_lowest_and_highest_pixel_to_fill_in_current_stripe(t_raycast *itens, t_data *data)
{
	if(itens->drawStart < 0)
		itens->drawStart = 0;
	itens->drawEnd = itens->lineHeight / 2 + 480 / 2;
	if(itens->drawEnd >= 480)
		itens->drawEnd = 480 - 1;
}

void	testes(t_data *data)
{
	t_raycast	itens;
	int 		side; //was a NS or a EW wall hit?

	init_raycast(&itens);
	for (int x = 0; x < 640; x++)
   	{
		calculate_ray_position_direction(&itens, data, x);
		position_player_map(&itens, data);
		length_of_ray_from_current_position_to_next_x_or_y_side(&itens);
		length_of_ray_from_one_x_or_y_side_to_next_x_or_y_side(&itens, data);
		jump_next_square_and_verify_hit_wall(&itens, data, 0);
		calculate_height_of_line_to_draw_on_screen(&itens, data);
		calculate_lowest_and_highest_pixel_to_fill_in_current_stripe(&itens, data);
		verLine(data, x, itens.drawStart, itens.drawEnd, RGB_RED);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
}

