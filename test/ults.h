/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ults.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:53:17 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:31:49 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_position_player(t_map *data, int position_x, int position_y)
{
	data->player[P_X] = position_x;
	data->player[P_Y] = position_y;
}
void	fake_alloc_map(t_map *data, int position_x, int position_y, int size, char *file_name)
{
	ft_bzero(data, sizeof(t_data));
	set_flag(FALSE);
	data->size_y = size;
	set_position_player(data, position_x, position_y);
	open_file_status(&data->fd, file_name);
	alloc_map_status(data, data->fd);
}

char	**retorne_fake_map(int size, char *file_name)
{
	char **map;
	int fd;

	size += 1;
	map = (char **)malloc(sizeof(char *) * size);
	if (map == NULL)
		msg_and_error("Error in creat pointer of map in tst", NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		printf("Error: not open file in ults.h\n");
	else
	{
		for (int i = 0; i < size; i++)
			map[i] = get_next_line(fd);
	}
	return (map);
}
