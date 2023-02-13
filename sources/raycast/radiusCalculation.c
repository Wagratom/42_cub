/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiusCalculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:34:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 23:40:26 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//length of ray from current position to next x or y-side

void	length_ray(t_raycast *itens)
{
	itens->delta_dist[P_X] = fabs(1 / itens->ray_dir[P_X]);
	itens->delta_dist[P_Y] = fabs(1 / itens->ray_dir[P_Y]);
}

void	side_x(t_raycast *itens, t_data *data)
{
	double	aux;

	if (itens->ray_dir[P_X] < 0)
	{
		itens->step[P_X] = -1;
		aux = player_p_x(data) - itens->map[P_X];
		itens->side_dist[P_X] = aux * itens->delta_dist[P_X];
	}
	else
	{
		itens->step[P_X] = 1;
		aux = itens->map[P_X] + 1.0 - player_p_x(data);
		itens->side_dist[P_X] = aux * itens->delta_dist[P_X];
	}
}

void	side_y(t_raycast *itens, t_data *data)
{
	double	aux;

	if (itens->ray_dir[P_Y] < 0)
	{
		itens->step[P_Y] = -1;
		aux = player_p_y(data) - itens->map[P_Y];
		itens->side_dist[P_Y] = aux * itens->delta_dist[P_Y];
	}
	else
	{
		itens->step[P_Y] = 1;
		aux = itens->map[P_Y] + 1.0 - player_p_y(data);
		itens->side_dist[P_Y] = aux * itens->delta_dist[P_Y];
	}
}

//length of ray from one x or y-side to next x or y-side

void	length_ray_next_x_y(t_raycast *itens, t_data *data)
{
	side_x(itens, data);
	side_y(itens, data);
}
