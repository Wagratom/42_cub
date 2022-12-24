/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/23 21:59:07 by wwallas-         ###   ########.fr       */
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

void	calculate_ray_position_direction(t_raycast *itens, int x)
{
	itens->cameraX = 2 * x / (double)640 - 1; //x-coordinate in camera space
	itens->rayDir[P_X] = itens->dir[P_X] + itens->plane[P_X] * itens->cameraX;
	itens->rayDir[P_Y] = itens->dir[P_Y] + itens->plane[P_Y] * itens->cameraX;
}

// which box of the map we're in
void	player_position_on_map(t_raycast *itens, t_data *data)
{
	itens->map[P_X] = (int)player_posX(data);
	itens->map[P_Y] = (int)player_posY(data);
}

void	len_ray_next_position(t_raycast *itens)
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

void	len_ray_x_or_y_next_position_x_or_y(t_raycast *itens, t_data *data)
{
	side_x(itens, data);
	side_y(itens, data);
}

void	testes(t_data *data)
{
	t_raycast	itens;

	init_raycast(&itens);
	for (int x = 0; x < 640; x++)
   	{
		calculate_ray_position_direction(&itens, x);
		player_position_on_map(&itens, data);
		len_ray_next_position(&itens);
		len_ray_x_or_y_next_position_x_or_y(&itens, data);
		//sideDist = length of ray from current position to next x or y-side
	
		int side;		//was a NS or a EW wall hit?
		int hit = 0;	//was there a wall hit?
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (itens.sideDist[P_X] < itens.sideDist[P_Y])
			{
				itens.sideDist[P_X] += itens.deltaDist[P_X];
				itens.map[P_X] += itens.step[P_X];
				side = 0;
			}
			else
			{
				itens.sideDist[P_Y] += itens.deltaDist[P_Y];
				itens.map[P_Y] += itens.step[P_Y];
				side = 1;
			}
			//Check if ray has hit a wall
			print_larger_pixel_tst(data, itens.map[P_X] * 5, itens.map[P_Y] * 5, RGB_RED);
			if (data->map.map[itens.map[P_Y]][itens.map[P_X]] == '1') hit = 1;
		}

		if (side == 0)
			itens.perpWallDist = (itens.map[P_X] - player_posX(data) + (1 - itens.step[P_X]) / 2) / itens.rayDir[P_X];
		else
			itens.perpWallDist = (itens.map[P_Y] - player_posY(data) + (1 - itens.step[P_Y]) / 2) / itens.rayDir[P_Y];

		int lineHeight = (int)(480 / itens.perpWallDist);
		//printf("%d\n", lineHeight);

		int drawStart = -lineHeight / 2 + 480 / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 480 / 2;
		if(drawEnd >= 480)
			drawEnd = 480 - 1;
		verLine(data, x, drawStart, drawEnd, RGB_RED);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
}

