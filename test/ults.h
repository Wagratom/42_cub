/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ults.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/30 15:32:47 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	fake_alloc_map(t_map *data, int position_x, int position_y, int size, char *file_name)
{
	ft_bzero(data, sizeof(t_data));
	set_flag(FALSE);
	data->file_name = file_name;
	data->size_y = size;
	data->player[P_X] = position_x;
	data->player[P_Y] = position_y;
	alloc_map_status(data);
}
