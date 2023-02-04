/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:56:19 by hectfern          #+#    #+#             */
/*   Updated: 2023/02/04 13:53:50 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_direction_player(t_map *data, char _char)
{
	if (!is_special_char(_char))
		return ;
	if (_char == 'N')
	{
		data->dir[P_Y] = -1;
		data->plane[P_X] = 0.66;
	}
	else if (_char == 'S')
	{
		data->dir[P_Y] = 1;
		data->plane[P_X] = -0.66;
	}
	else if (_char == 'E')
	{
		data->dir[P_X] = 1;
		data->plane[P_Y] = 0.66;
	}
	else if (_char == 'W')
	{
		data->dir[P_X] = -1;
		data->plane[P_Y] = -0.66;
	}
}
