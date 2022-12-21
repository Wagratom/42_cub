/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/21 11:47:39 by wwallas-         ###   ########.fr       */
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
		double cameraX = 2 * x / (double)640 - 1; //x-coordinate in camera space
		double rayDirX = itens.dir[P_X] + itens.plane[P_X] * cameraX;
		double rayDirY = itens.dir[P_Y] + itens.plane[P_Y] * cameraX;

		// printf("rayDirX = %f rayDirY = %f\n", rayDirX, rayDirY);
		// print_larger_pixel_tst(data, rayDirX, rayDirY, RGB_RED);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

		// which box of the map we're in

		int mapX = (int)player_posX(data);
		int mapY = (int)player_posY(data);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;


		//length of ray from one x or y-side to next x or y-side
		//double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
		//double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		//printf("rayDirX = %f rayDirY = %f\n", deltaDistX, deltaDistY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?


		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player_posX(data) - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player_posX(data)) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player_posY(data) - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player_posY(data)) * deltaDistY;
		}

		//printf("%f %f\n", deltaDistX, deltaDistY);
		//print_larger_pixel_tst(data, sideDistX, sideDistY, RGB_RED);
		//mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

		//printf("%d %d\n", mapX, mapY);
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			print_larger_pixel_tst(data, mapX * 5, mapY * 5, RGB_RED);
			if (data->map.map[mapY][mapX] == '1') hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - player_posX(data) + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - player_posY(data) + (1 - stepY) / 2) / rayDirY;

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

