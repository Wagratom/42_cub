/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 16:53:09 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_larger_pixel_tst(t_data *data, int x, int y, int color)
{
	int			len_x;
	int			size_y;

	save_value_x(x);
	len_x = get_save_x() + 1;
	size_y = y + 1;
	while (y++ < size_y)
	{
		x = get_save_x();
		while (x++ < len_x)
			my_mlx_pixel_put(&data->img, x, y, color);
	}
	save_value_x(0);
}

void	testes(t_data *data)
{
	float	posX = data->map.p_player[P_X];
	float	posY = data->map.p_player[P_Y];

	float	dirX = 1;
	float	dirY = 1;									//initial direction vector

	float planeX = 0, planeY = 0.66; 			// 0.66
	for (int x = 0; x < 200; x++)
   	{
		//calculate ray position and direction
		float cameraX = 10 * x / (float)200 - 1; //x-coordinate in camera space
		// printf("camera = %f\n", cameraX);
		float rayDirX = dirX + planeX * cameraX;
		float rayDirY = dirY + planeY * cameraX;
		//printf("rayDirX = %f rayDirY = %f\n", rayDirX, rayDirY);
		print_larger_pixel_tst(data, rayDirX, rayDirY, RGB_RED); 
	}
		//which box of the map we're in
	// int mapX = (int)(posX);
	// int mapY = (int)posY;

	// //length of ray from current position to next x or y-side
	// double sideDistX;
	// double sideDistY;

	//  //length of ray from one x or y-side to next x or y-side
	// double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
	// double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
	// double perpWallDist;

	// //what direction to step in x or y-direction (either +1 or -1)
	// int stepX;
	// int stepY;

	// int hit = 0; //was there a wall hit?
	// int side; //was a NS or a EW wall hit?
	//}

}

