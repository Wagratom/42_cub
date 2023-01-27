/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:13:03 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	alloc_ptr_status(t_map *data)
{
	data->map = (char **)ft_calloc(data->size_y, sizeof(char *));
	if (data->map == NULL)
		return (FALSE);
	debug_print(has_flag(), "Allocated Ptr: OK\n");
	return (TRUE);
}

void	alloc_map(t_map *data)
{
	int	tmp;

	tmp = -1;
	while (++tmp < data->size_y)
		data->map[tmp] = get_next_line(data->fd);
	data->map[tmp] = get_next_line(data->fd);
	debug_print(has_flag(), "Allocated Map : OK\n");
}

void	remove_char_of_player(t_map *data)
{
	int	posi_y;
	int	posi_x;

	posi_y = (int)data->player[P_Y];
	posi_x = (int)data->player[P_X];
	data->map[posi_y][posi_x] = '0';
	debug_print(has_flag(), "Removing char map: OK\n");
}

t_bool	alloc_map_status(t_map *data)
{
	debug_print(has_flag(), "\tallocating the map\n");
	if (open_file_or_die(data) == FALSE)
		return (FALSE);
	if (alloc_ptr_status(data) == FALSE)
		return (FALSE);
	alloc_map(data);
	remove_char_of_player(data);
	if (has_flag())
		draw_mapingD(data->map);
	return (TRUE);
}
