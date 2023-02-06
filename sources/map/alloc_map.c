/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:43:17 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	alloc_ptr_status(t_map *data, int size)
{

	debug_printc(has_flag(), NULL, "Allocated ptr for full_map");
	data->full_map = (char **)ft_calloc((size + 1), sizeof(char *));
	if (data->full_map == NULL)
		return (msg_and_error(NULL, "Error: Not allocate ptr"));
	debug_printi(has_flag(), "Size ptr: ", size);
	return (TRUE);
}

t_bool	alloc_map_full_map(t_map *data, int size, int fd)
{
	int	tmp;

	debug_printc(has_flag(), NULL, "Allocating Full_Map");
	tmp = -1;
	while (++tmp < size)
	{
		if (!get_valid_line(&data->full_map[tmp], fd))
			return (msg_and_error(NULL, "Error: not get valid line in map\n"));
	}
	data->full_map[tmp] = get_next_line(fd);
	draw_mapingd(data->full_map);
	return (TRUE);
}

#define MINI_MAP_ERR "Pointer full map is NULL, Not creat mini map"
#define INIT_MINI_MAP_ERR "The start of the mini map is bigger than the size of the full map"

t_bool	create_mini_map(t_map *data)
{
	debug_printc(has_flag(), NULL, "Allocating Mine_Map");
	if (data->full_map == NULL)
		return (msg_and_error("Error: ", MINI_MAP_ERR));
	if (ft_array_len(data->full_map) <= data->size_d_map)
		return (msg_and_error("Error: ", INIT_MINI_MAP_ERR));
	data->mini_map = &data->full_map[data->size_d_map];
	draw_mapingd(data->mini_map);
	return (TRUE);
}

t_bool	alloc_map_status(t_map *data, int fd)
{
	int	full_size;

	full_size = data->size_y + data->size_d_map;
	if (!check_parameters(data, fd))
		return (FALSE);
	if (!alloc_ptr_status(data, full_size))
		return (FALSE);
	if (!alloc_map_full_map(data, full_size, fd))
		return (FALSE);
	if (!create_mini_map(data))
		return (FALSE);
	remove_char_of_player(data);
	return (TRUE);
}
