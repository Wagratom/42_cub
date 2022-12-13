/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/06 14:07:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	alloc_ptr(t_map *data)
{
	data->map = (char **)ft_calloc(data->size_y, sizeof(char *));
}

void	alloc_map(t_map *data)
{
	int	tmp;

	tmp = -1;
	while (++tmp < data->size_y)
		data->map[tmp] = get_next_line(data->fd);
	data->map[tmp] = get_next_line(data->fd);
}

void	alloc_map_or_die(t_map *data)
{
	open_file_or_die(data);
	alloc_ptr(data);
	alloc_map(data);
	draw_map_debug(data->map);
}
