/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:28:50 by hectfern          #+#    #+#             */
/*   Updated: 2023/01/07 16:28:31 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_ray_dir(t_ray *ray)
{
	t_pos	map;

	map.x = (int)ray->pos.x;
	map.y = (int)ray->pos.y;
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void	set_perp_wall_dist(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray;
	if (ray->side)
	{
		ray->perp_wall_dist = (ray->pos.y - data->player.pos.y \
				+ (1 - ray->step.y) / 2) / ray->direction.y;
		ray->color = 0x00FFFFFF;
	}
	else
	{
		ray->perp_wall_dist = (ray->pos.x - data->player.pos.x \
				+ (1 - ray->step.x) / 2) / ray->direction.x;
		ray->color = 0x00AAAAAA;
	}
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
}

void	dda_algorithm(t_data *data)
{
	int		hit;
	char	**map;

	hit = 0;
	map = data->map.map;
	// printf("\nray.side_dist += ray.delta_dist\n");
	// printf("ray.pos += ray.step\n\n");
	while (!hit)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.pos.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.pos.y += data->ray.step.y;
			data->ray.side = 1;
		}
		printf("ray.pos.x: %d ray.pos.y: %d\n", (int)data->ray.pos.x, (int)data->ray.pos.y);
		printf("ray.side_dist.x: %.1f ray.side_dist.y: %.1f\n", data->ray.side_dist.x, data->ray.side_dist.y);
		printf("ray.step.x: %.1f ray.step.y: %.1f\n", data->ray.step.x, data->ray.step.y);
		printf("\n");
		usleep(500);
		if (map[(int)data->ray.pos.x][(int)data->ray.pos.y] == '1')
			hit = !hit;
	}
	set_perp_wall_dist(data);
}

void	draw_line_ray(t_data *data, int x)
{
	int	end;
	int	start;

	end = data->ray.line_end;
	start = data->ray.line_start;
	while (start < end)
	{
		my_mlx_pixel_put(&data->img, x, start, data->ray.color);
		start++;
	}
}
