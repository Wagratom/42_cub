/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:03:45 by hectfern          #+#    #+#             */
/*   Updated: 2023/01/19 14:09:08 by wwalas-          ###   ########.fr       */
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
	// printf("\nray->camera_x = %f | ray->direction.x = %f | ray->direction.y = %f\n", ray->camera_x, ray->direction.x, ray->direction.y);
	// usleep(5000);
}

void	calculate_delta(t_ray *ray)
{
	// if (ray->direction.x == 0)
	// 	ray->delta_dist.x = 0;
	// else
	// 	ray->delta_dist.x = fabs(1 / ray->direction.x);
	ray->delta_dist.x = fabs(1 / ray->direction.x);
	// if (ray->direction.y == 0)
	// 	ray->delta_dist.y = 0;
	// else
	// 	ray->delta_dist.y = fabs(1 / ray->direction.y);
	ray->delta_dist.y = fabs(1 / ray->direction.y);

	// printf("\nray->delta_dist.x = %f | ray->delta_dist.y = %f\n", ray->delta_dist.x, ray->delta_dist.y);
	// usleep(5000);
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
		check_ray_dir(data);
		set_perp_wall_dist(data);
		ray->line_start = (HEIGHT - ray->line_height) / 2;
		ray->line_end = (HEIGHT + ray->line_height) / 2;
		if (ray->line_start < 0)
			ray->line_start = 0;
		if (ray->line_end >= HEIGHT)
			ray->line_end = HEIGHT - 1;
		dda_algorithm(data);
		draw_line_ray(data, x);
	}
}
