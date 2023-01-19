/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:28:50 by hectfern          #+#    #+#             */
/*   Updated: 2023/01/19 14:24:48 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// void	check_ray_dir(t_ray *ray)
// {
// 	t_pos	map;

// 	map.x = (int)ray->pos.x;
// 	map.y = (int)ray->pos.y;
// 	if (ray->direction.x < 0)
// 	{
// 		ray->step.x = -1;
// 		ray->side_dist.x = (ray->pos.x - map.x) * ray->delta_dist.x;
// 		printf("\nray->side_dist.x = %f | pos.x = %f | map.x = %f | delta_dist.x = %f\n", ray->side_dist.x, ray->pos.x, map.x, ray->delta_dist.x);
// 		usleep(5000);
// 	}
// 	else
// 	{
// 		ray->step.x = 1;
// 		ray->side_dist.x = (map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
// 		printf("\nray->side_dist.x = %f | pos.x = %f | map.x = %f| delta_dist.x = %f\n", ray->side_dist.x, ray->pos.x, map.x, ray->delta_dist.x);
// 		usleep(5000);
// 	}
// 	if (ray->direction.y < 0)
// 	{
// 		ray->step.y = -1;
// 		ray->side_dist.y = (ray->pos.y - map.y) * ray->delta_dist.y;
// 		printf("\nray->side_dist.y = %f | pos.y = %f | map.y = %f | delta_dist.y = %f\n", ray->side_dist.y, ray->pos.y, map.y, ray->delta_dist.y);
// 		usleep(5000);
// 	}
// 	else
// 	{
// 		ray->step.y = 1;
// 		ray->side_dist.y = (map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
// 		printf("\nray->side_dist.y = %f | pos.y = %f | map.y = %f | delta_dist.y = %f\n", ray->side_dist.y, ray->pos.y, map.y, ray->delta_dist.y);
// 		usleep(5000);
// 	}
// }

void	check_ray_dir(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	ray = &data->ray;
	player = &data->player;
	ray->pos.x = player->pos.x;
	ray->pos.y = player->pos.y;
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->pos.x) * ray->delta_dist.x;
		// printf("\nray->side_dist.x = %f | pos.x = %f | ray->pos.x = %f | delta_dist.x = %f\n", ray->side_dist.x, ray->pos.x, ray->pos.x, ray->delta_dist.x);
		// usleep(5000);
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->pos.x + 1.0 - player->pos.x) * ray->delta_dist.x;
		// printf("\nray->side_dist.x = %f | pos.x = %f | ray->pos.x = %f| delta_dist.x = %f\n", ray->side_dist.x, ray->pos.x, ray->pos.x, ray->delta_dist.x);
		// usleep(5000);
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->pos.y) * ray->delta_dist.y;
		// printf("\nray->side_dist.y = %f | pos.y = %f | ray->pos.y = %f | delta_dist.y = %f\n", ray->side_dist.y, ray->pos.y, ray->pos.y, ray->delta_dist.y);
		// usleep(5000);
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->pos.y + 1.0 - player->pos.y) * ray->delta_dist.y;
		// printf("\nray->side_dist.y = %f | pos.y = %f | ray->pos.y = %f | delta_dist.y = %f\n", ray->side_dist.y, ray->pos.y, ray->pos.y, ray->delta_dist.y);
		// usleep(5000);
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
		// printf("\nray->perp_wall_dist = %f | ray->pos.y = %f | player.pos.y = %f | ray->step.y = %f | ray->direction.y = %f\n", ray->perp_wall_dist, ray->pos.y, data->player.pos.y, ray->step.y, ray->direction.y);
		// usleep(5000);
	}
	else
	{
		ray->perp_wall_dist = (ray->pos.x - data->player.pos.x \
				+ (1 - ray->step.x) / 2) / ray->direction.x;
		ray->color = 0x00AAAAAA;
		// printf("\nray->perp_wall_dist = %f | ray->pos.x = %f | player.pos.x = %f | ray->step.x = %f | ray->direction.x = %f\n", ray->perp_wall_dist, ray->pos.x, data->player.pos.x, ray->step.x, ray->direction.x);
		// usleep(5000);
	}
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	// printf("\nray->line_height = %d | HEIGHT = %d | ray->perp_wall_dist = %f\n", ray->line_height, HEIGHT, ray->perp_wall_dist);
	// usleep(5000);
}

void	dda_algorithm(t_data *data)
{
	int		hit;
	char	**map;

	hit = 0;
	map = data->map.map;
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
		// printf("\nray.pos.x: %d ray.pos.y: %d\n", (int)data->ray.pos.x, (int)data->ray.pos.y);
		// printf("ray.side_dist.x: %f ray.side_dist.y: %f\n", data->ray.side_dist.x, data->ray.side_dist.y);
		// printf("ray.step.x: %.1f ray.step.y: %.1f\n", data->ray.step.x, data->ray.step.y);
		// printf("\n");
		// usleep(5000);
		print_larger_pixel(data, (int)data->ray.pos.y * 5, (int)data->ray.pos.x * 5, RGB_RED);
		if (map[(int)data->ray.pos.x][(int)data->ray.pos.y] == '1')
			hit = !hit;
	}
	set_perp_wall_dist(data);
	data->ray.line_start = (HEIGHT - data->ray.line_height) / 2;
	if (data->ray.line_start < 0)
		data->ray.line_start = 0;
	data->ray.line_end = (HEIGHT + data->ray.line_height) / 2;
	if (data->ray.line_end >= HEIGHT)
		data->ray.line_end = HEIGHT - 1;
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
