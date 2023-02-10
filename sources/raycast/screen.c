/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:32:09 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/06 17:50:23 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	calculate_ray_position_direction(t_raycast *itens, int x)
{
	itens->cameraX = 2 * x / (double)WIDTH - 1;
	itens->rayDir[P_X] = itens->dir[P_X] + itens->plane[P_X] * itens->cameraX;
	itens->rayDir[P_Y] = itens->dir[P_Y] + itens->plane[P_Y] * itens->cameraX;
}

//Calculate height of line to draw on screen

void	calculate_height_line(t_raycast *itens)
{
	itens->lineHeight = (int)(HEIGHT / itens->perpWallDist);
	itens->drawStart = -itens->lineHeight / 2 + HEIGHT / 2;
}
