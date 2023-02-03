/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/03 14:07:29 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	check_parameters(t_map *data, int fd)
{
	if (data == NULL)
		return (FALSE);
	if (fd < 0)
		return (FALSE);
	return (TRUE);
}

t_bool	alloc_ptr_status(t_map *data)
{
	int	full_size;

	full_size = data->size_y + data->size_d_map;
	data->full_map = (char **)ft_calloc((full_size + 1), sizeof(char *));
	if (data->full_map != NULL)
	{
		debug_printC(has_flag(), "Allocated: ", "Ptr OK");
		debug_printI(has_flag(), "Size ptr: ", full_size);
		return (TRUE);
	}
	write(2, "Error: Not allocate ptr\n", 24);
	return (FALSE);
}

static t_bool	get_valid_line(char **dst, int fd)
{
	*dst = get_next_line(fd);
	if (*dst == NULL)
		return (FALSE);
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
		if (get_valid_line(&data->full_map[tmp], fd))
			continue;
		write(2, "Error: not get line valid in map\n", 33);
		return (FALSE);
	}
	data->full_map[tmp] = get_next_line(fd);
	debug_printC(has_flag(), "Allocated :", " Full_Map OK");
	if (has_flag())
		draw_mapingD(data->full_map);
	return (TRUE);
}

void	remove_char_of_player(t_map *data)
{
	int	posi_y;
	int	posi_x;

	posi_y = (int)data->player[P_Y];
	posi_x = (int)data->player[P_X];
	data->mini_map[posi_y][posi_x] = '0';
	debug_printC(has_flag(), "Removing char map: ", "OK\n");
}

t_bool	create_mini_map(t_map *data)
{
	if (data->full_map == NULL)
		return (FALSE);
	if (ft_array_len(data->full_map) <= data->size_d_map)
		return (FALSE);
	data->mini_map = &data->full_map[data->size_d_map];
	debug_printC(has_flag(), "Allocated :", " Mine_Map OK");
	if (has_flag())
		draw_mapingD(data->mini_map);
	return (TRUE);
}
t_bool	alloc_map_status(t_map *data, int fd)
{
	debug_printC(has_flag(), NULL, "\tallocating the map");
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
