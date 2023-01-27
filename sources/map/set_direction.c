/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:56:19 by hectfern          #+#    #+#             */
/*   Updated: 2023/01/27 16:11:07 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

void	set_direction_player(t_map *data, char c)
{
	if (c == 'N')
	{
		data->dir[P_Y] = -1;
		data->plane[P_X] = 0.66;
	}
	else if (c == 'S')
	{
		data->dir[P_Y] = 1;
		data->plane[P_X] = -0.66;
	}
	else if (c == 'E')
	{
		data->dir[P_X] = 1;
		data->plane[P_Y] = 0.66;
	}
	else if (c == 'W')
	{
		data->dir[P_X] = -1;
		data->plane[P_Y] = -0.66;
	}
}
