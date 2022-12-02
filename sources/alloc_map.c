/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/01 17:25:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>

void	alloc_map(t_map *data)
{
	int	tmp;

	tmp = -1;
	open_file(data);
	data->map = (char **)ft_calloc(data->size_y, sizeof(char *));
	while (++tmp < data->size_y)
		data->map[tmp] = get_next_line(data->fd);
	data->map[tmp] = get_next_line(data->fd);
	//draw_map(data->map);
}
