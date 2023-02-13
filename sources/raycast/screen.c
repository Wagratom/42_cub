/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:32:09 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 23:48:57 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	calculate_ray_position_direction(t_raycast *itens, int x)
{
	itens->cam_x = 2 * x / (double)WIDTH - 1;
	itens->ray_dir[P_X] = itens->dir[P_X] + itens->plane[P_X] * itens->cam_x;
	itens->ray_dir[P_Y] = itens->dir[P_Y] + itens->plane[P_Y] * itens->cam_x;
}

//Calculate height of line to draw on screen

void	calculate_height_line(t_raycast *itens)
{
	itens->l_height = (int)(HEIGHT / itens->perp_wall);
	itens->d_start = -itens->l_height / 2 + HEIGHT / 2;
}
