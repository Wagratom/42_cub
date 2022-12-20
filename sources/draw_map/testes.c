/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/20 17:31:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <math.h>

void	print_larger_pixel_tst(t_data *data, int x, int y, int color)
{
	int			len_x;
	int			size_y;

	save_value_x(x);
	len_x = get_save_x() + 5;
	size_y = y + 5;
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
		// mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	testes(t_data *data)
{

	double	posX = data->map.p_player[P_X];
	double	posY = data->map.p_player[P_Y];

	double	dirX = -1, dirY = 0;									//initial direction vector

	double planeX = 0, planeY = 0.66;					// 0.66

	for (int x = 0; x < 640; x++)
   	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)640 - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		// printf("rayDirX = %f rayDirY = %f\n", rayDirX, rayDirY);
		// print_larger_pixel_tst(data, rayDirX, rayDirY, RGB_RED);
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

		// which box of the map we're in

		int mapX = (int)posX;
		int mapY = (int)posY;

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
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
			mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
			printf("x = %d y = %d\n", mapY, mapX);
			if (data->map.map[mapY][mapX] == '1') hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(480 / perpWallDist);
		//printf("%d\n", lineHeight);

		int drawStart = -lineHeight / 2 + 480 / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 480 / 2;
		if(drawEnd >= 480)
			drawEnd = 480 - 1;

		verLine(data, x, drawStart, drawEnd, RGB_RED);
	}
	// //what direction to step in x or y-direction (either +1 or -1)
	// int stepX;
	// int stepY;

	// int hit = 0; //was there a wall hit?
	// int side; //was a NS or a EW wall hit?
	//}

}

