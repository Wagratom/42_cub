/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:03:45 by hectfern          #+#    #+#             */
/*   Updated: 2022/12/31 12:17:08 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	calculate_ray_dir(t_data *data, int x)
{
	t_ray		*ray;
	t_player	*player;

	ray = &data->ray;
	player = &data->player;
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->direction.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->direction.y = player->dir.y + player->plane.y * ray->camera_x;
}

void	calculate_delta(t_ray *ray)
{
	ray->delta_dist.x = fabs(1 / ray->direction.x);
	ray->delta_dist.y = fabs(1 / ray->direction.y);
}

void	calculate(t_data *data)
{
	int		x;
	t_ray	*ray;

	x = -1;
	ray = &data->ray;
	while (++x < WIDTH)
	{
		calculate_ray_dir(data, x);
		calculate_delta(ray);
		check_ray_dir(ray);
		set_perp_wall_dist(data);
		ray->line_start = (HEIGHT - ray->line_height) / 2;
		ray->line_end = (HEIGHT + ray->line_height) / 2;
		if (ray->line_start < 0)
			ray->line_start = 0;
		if (ray->line_end >= HEIGHT)
			ray->line_end = HEIGHT - 1;
		draw_line_ray(data, x);
	}
}
