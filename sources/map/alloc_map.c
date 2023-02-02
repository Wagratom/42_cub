/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/02 16:40:42 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	alloc_ptr_status(t_map *data)
{
	data->map = (char **)ft_calloc((data->size_y + 1), sizeof(char *));
	if (data->map == NULL)
		return (FALSE);
	debug_printC(has_flag(), "Allocated: ", "Ptr OK");
	return (TRUE);
}

void	alloc_map(t_map *data)
{
	int	tmp;

	tmp = -1;
	while (++tmp < data->size_y)
		data->map[tmp] = get_next_line(data->fd);
	data->map[tmp] = get_next_line(data->fd);
	debug_printC(has_flag(), "Allocated :", " Map OK");
}

void	remove_char_of_player(t_map *data)
{
	int	posi_y;
	int	posi_x;

	posi_y = (int)data->player[P_Y];
	posi_x = (int)data->player[P_X];
	data->map[posi_y][posi_x] = '0';
	debug_printC(has_flag(), "Removing char map: ", "OK");
}

t_bool	alloc_map_status(t_map *data)
{
	debug_printC(has_flag(), NULL, "\tallocating the map");
	if (!open_file_status(&data->fd, data->file_name))
		return (FALSE);
	if (!alloc_ptr_status(data))
		return (FALSE);
	alloc_map(data);
	remove_char_of_player(data);
	if (has_flag())
		draw_mapingD(data->map);
	return (TRUE);
}
