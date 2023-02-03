/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ults.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/02 17:23:20 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	fake_alloc_map(t_map *data, int position_x, int position_y, int size, char *file_name)
{
	ft_bzero(data, sizeof(t_data));
	set_flag(FALSE);
	data->size_y = size;
	data->player[P_X] = position_x;
	data->player[P_Y] = position_y;
	open_file_status(&data->fd, file_name);
	alloc_map_status(data, data->fd);
}

char	**retorne_fake_map(int size, char *file_name)
{
	char **map;
	int fd;

	map = (char **)malloc(sizeof(char *) * size);
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		printf("Error: not open file in ults.h\n");
	else
	{
		for (int i = 0; i < 24; i++)
			map[i] = get_next_line(fd);
	}
	return (map);
}
