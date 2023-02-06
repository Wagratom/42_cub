/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 14:41:19 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	alloc_ptr_status(t_map *data)
{
	int	full_size;

	full_size = data->size_y + data->size_d_map;
	data->full_map = (char **)ft_calloc((full_size + 1), sizeof(char *));
	if (data->full_map == NULL)
		return (msg_and_error(NULL, "Error: Not allocate ptr"));
	debug_printc(has_flag(), NULL, "Allocated ptr for full_map");
	debug_printi(has_flag(), "Size ptr: ", full_size);
	return (TRUE);
}

t_bool	alloc_map_full_map(t_map *data, int fd)
{
	int	full_size;
	int	tmp;

	tmp = -1;
	full_size = data->size_y + data->size_d_map;
	while (++tmp < full_size)
	{
		if (!get_valid_line(&data->full_map[tmp], fd))
			return (msg_and_error(NULL, "Error: not get line valid in map\n"));
	}
	data->full_map[tmp] = get_next_line(fd);
	debug_printc(has_flag(), NULL, "Allocated Full_Map");
	draw_mapingd(data->full_map);
	return (TRUE);
}

t_bool	create_mini_map(t_map *data)
{
	if (data->full_map == NULL)
		return (FALSE);
	if (ft_array_len(data->full_map) <= data->size_d_map)
		return (FALSE);
	data->mini_map = &data->full_map[data->size_d_map];
	debug_printc(has_flag(), NULL, "Allocated  Mine_Map");
	if (has_flag())
		draw_mapingd(data->mini_map);
	return (TRUE);
}

t_bool	alloc_map_status(t_map *data, int fd)
{
	if (!check_parameters(data, fd))
		return (FALSE);
	if (!alloc_ptr_status(data))
		return (FALSE);
	if (!alloc_map_full_map(data, fd))
		return (FALSE);
	if (!create_mini_map(data))
		return (FALSE);
	remove_char_of_player(data);
	return (TRUE);
}
