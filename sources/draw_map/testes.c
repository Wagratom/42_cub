/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/21 17:26:16 by wwallas-         ###   ########.fr       */
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
	itens->dir[P_Y] = 0;

	itens->plane[P_X] = 0;
	itens->plane[P_Y] = 0.66;
}

void	testes(t_data *data)
{
	t_raycast	itens;

	init_raycast(&itens);
	for (int x = 0; x < 640; x++)
   	{
		//calculate ray position and direction
		itens.cameraX = 2 * x / (double)640 - 1; //x-coordinate in camera space
		itens.rayDir[P_X] = itens.dir[P_X] + itens.plane[P_X] * itens.cameraX;
		itens.rayDir[P_Y] = itens.dir[P_Y] + itens.plane[P_Y] * itens.cameraX;

		// which box of the map we're in
		itens.map[P_X] = (int)player_posX(data);
		itens.map[P_Y] = (int)player_posY(data);

		double deltaDistX = fabs(1 / itens.rayDir[P_X]);
		double deltaDistY = fabs(1 / itens.rayDir[P_Y]);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//sideDist = length of ray from current position to next x or y-side
		if (itens.rayDir[P_X] < 0)
		{
			stepX = -1;
			itens.sideDist[P_X] = (player_posX(data) - itens.map[P_X]) * deltaDistX;
		}
		else
		{
			stepX = 1;
			itens.sideDist[P_X] = (itens.map[P_X] + 1.0 - player_posX(data)) * deltaDistX;
		}
		if (itens.rayDir[P_Y] < 0)
		{
			stepY = -1;
			itens.sideDist[P_Y] = (player_posY(data) - itens.map[P_Y]) * deltaDistY;
		}
		else
		{
			stepY = 1;
			itens.sideDist[P_Y] = (itens.map[P_Y] + 1.0 - player_posY(data)) * deltaDistY;
		}

		//printf("%f %f\n", deltaDistX, deltaDistY);
		//print_larger_pixel_tst(data, sideDistX, sideDistY, RGB_RED);
		//mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

		//printf("%d %d\n", mapX, mapY);
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (itens.sideDist[P_X] < itens.sideDist[P_Y])
			{
				itens.sideDist[P_X] += deltaDistX;
				itens.map[P_X] += stepX;
				side = 0;
			}
			else
			{
				itens.sideDist[P_Y] += deltaDistY;
				itens.map[P_Y] += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			print_larger_pixel_tst(data, itens.map[P_X] * 5, itens.map[P_Y] * 5, RGB_RED);
			if (data->map.map[itens.map[P_Y]][itens.map[P_X]] == '1') hit = 1;
		}

		if (side == 0)
			perpWallDist = (itens.map[P_X] - player_posX(data) + (1 - stepX) / 2) / itens.rayDir[P_X];
		else
			perpWallDist = (itens.map[P_Y] - player_posY(data) + (1 - stepY) / 2) / itens.rayDir[P_Y];

		int lineHeight = (int)(480 / perpWallDist);
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
	// //what direction to step in x or y-direction (either +1 or -1)
	// int stepX;
	// int stepY;

	// int hit = 0; //was there a wall hit?
	// int side; //was a NS or a EW wall hit?
	//}

}

