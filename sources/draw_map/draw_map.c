/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/06 15:10:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_block(t_data *data, int x, int y, char block)
{
	usleep(50000);
	printf("block = %c\n", block);
	if (block == '0')
		print_larger_pixel(data, (x * 8), (y * 8), RGB_WHITE);
	else if (block == '1')
		print_larger_pixel(data, (x * 8), (y * 8), RGB_MAROON);
	else if (block == 'W')
		print_larger_pixel(data, (x * 8), (y * 8), RGB_RED);
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
	while (data->map.map[++line])
	{
		draw_line(data, line);
		printf("\n");
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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
