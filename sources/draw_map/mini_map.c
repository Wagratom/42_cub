/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:18:29 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_block(t_data *data, int y, int x, char block)
{
	if (block == '0')
		print_larger_pixel(data, (y * 5), (x * 5), RGB_WHITE);
	else if (block == '1')
		print_larger_pixel(data, (y * 5), (x * 5), RGB_MAROON);
}

static void	draw_line(t_data *data, char *line, int y)
{
	int	x;

	x = -1;
	while (line[++x])
		print_block(data, y, x, line[x]);
}

void	draw_mini_map(t_data *data)
{
	int	line;

	line = -1;
	while (data->map.mini_map[++line])
		draw_line(data, data->map.mini_map[line], line);
}
