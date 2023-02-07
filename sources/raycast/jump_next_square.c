/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_next_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:11:26 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	nao_sei_oq_ta_acontecendo(t_raycast *itens, t_data *data)
{
	double	aux;

	aux = itens->map[P_X] - player_p_x(data) + (1 - itens->step[P_X]) / 2;
	if (itens->side == 0)
		itens->perpWallDist = aux / itens->rayDir[P_X];
	else
	{
		aux = itens->map[P_Y] - player_p_y(data) + (1 - itens->step[P_Y]) / 2;
		itens->perpWallDist = aux / itens->rayDir[P_Y];
	}
}

void	lance_ray_in_wall(t_raycast *itens, t_data *data)
{
	while (TRUE)
	{
		if (itens->sideDist[P_X] < itens->sideDist[P_Y])
		{
			itens->sideDist[P_X] += itens->deltaDist[P_X];
			itens->map[P_X] += itens->step[P_X];
			itens->side = 0;
		}
		else
		{
			itens->sideDist[P_Y] += itens->deltaDist[P_Y];
			itens->map[P_Y] += itens->step[P_Y];
			itens->side = 1;
		}
		print_larger_pixel(data, itens->map[P_Y] * 5, \
		itens->map[P_X] * 5, RED);
		if (data->map.mini_map[itens->map[P_Y]][itens->map[P_X]] == '1')
			return ;
	}
}

void	jump_next_square_and_verify_hit_wall(t_raycast *itens, t_data *data)
{
	lance_ray_in_wall(itens, data);
	nao_sei_oq_ta_acontecendo(itens, data);
}
