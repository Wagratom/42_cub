/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:38:48 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:22:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	draw_map_status(t_data *data)
{
	if (data->map.mini_map == NULL)
		return (msg_and_error(NULL, "can't draw the map, map doesn't exist"));
	draw_map(data);
	return (TRUE);
}

void	draw_map(t_data *data)
{
	render_background(data);
	draw_mini_map(data);
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
