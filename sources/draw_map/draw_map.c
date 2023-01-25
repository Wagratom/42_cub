/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 10:50:57 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	render_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, 0x87CEEB);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, 0x8B4513);
			x++;
		}
		y++;
	}
}

static void	print_block(t_data *data, int x, int y, char block)
{
	if (block == '0')
		print_larger_pixel(data, (x * 5), (y * 5), RGB_WHITE);
	else if (block == '1')
		print_larger_pixel(data, (x * 5), (y * 5), RGB_MAROON);
}

static void	draw_line(t_data *data, int y)
{
	char	*line;
	int		block;

	block = -1;
	line = data->map.map[y];
	while (line[++block])
		print_block(data, block, y, line[block]);
}

int	draw_map(t_data *data)
{
	int	line;

	line = -1;
	render_background(data);
	while (data->map.map[++line])
		draw_line(data, line);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}

int	draw_map_or_die(t_data *data)
{
	if (data->map.map == NULL)
	{
		printf("can't draw the map, map doesn't exist");
		return (FALSE);
	}
	return (draw_map(data));
}
