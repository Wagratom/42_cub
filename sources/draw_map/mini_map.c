/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:10:23 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_block(t_data *data, int position_y, int position_x, char block)
{
	if (block == '0')
		print_larger_pixel(data, (position_y * 5), (position_x * 5), RGB_WHITE);
	else if (block == '1')
		print_larger_pixel(data, (position_y * 5), (position_x * 5), RGB_MAROON);
}

static void	draw_line(t_data *data, char *line, int y)
{
	int	position_x;

	position_x = -1;
	while (line[++position_x])
		print_block(data, y, position_x, line[position_x]);
}

void	draw_mini_map(t_data *data)
{
	int	line;

	line = -1;
	while (data->map.mini_map[++line])
		draw_line(data, data->map.mini_map[line], line);
}
