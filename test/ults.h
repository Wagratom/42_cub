/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ults.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:17 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/04 14:08:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	fake_alloc_map(t_map *data, int position_x, int position_y, int size, char *file_name)
{
	ft_bzero(data, sizeof(t_data));
	data->file_name = file_name;
	data->size_y = size;
	data->p_player[P_X] = position_x;
	data->p_player[P_Y] = position_y;
	alloc_map_or_die(data);

}
