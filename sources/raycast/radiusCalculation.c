/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiusCalculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:34:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/07 13:04:47 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//length of ray from current position to next x or y-side

void	lengthRay(t_raycast *itens)
{
	itens->deltaDist[P_X] = fabs(1 / itens->rayDir[P_X]);
	itens->deltaDist[P_Y] = fabs(1 / itens->rayDir[P_Y]);
}

void	side_x(t_raycast * itens, t_data *data)
{
	if (itens->rayDir[P_X] < 0)
	{
		itens->step[P_X] = -1;
		itens->sideDist[P_X] = (player_posX(data) - itens->map[P_X]) * itens->deltaDist[P_X];
	}
	else
	{
		itens->step[P_X] = 1;
		itens->sideDist[P_X] = (itens->map[P_X] + 1.0 - player_posX(data)) * itens->deltaDist[P_X];
	}
}

void	side_y(t_raycast * itens, t_data *data)
{
	if (itens->rayDir[P_Y] < 0)
	{
		itens->step[P_Y] = -1;
		itens->sideDist[P_Y] = (player_posY(data) - itens->map[P_Y]) * itens->deltaDist[P_Y];
	}
	else
	{
		itens->step[P_Y] = 1;
		itens->sideDist[P_Y] = (itens->map[P_Y] + 1.0 - player_posY(data)) * itens->deltaDist[P_Y];
	}
}

//length of ray from one x or y-side to next x or y-side

void	lengthRayNext_x_y(t_raycast *itens, t_data *data)
{
	side_x(itens, data);
	side_y(itens, data);
}
