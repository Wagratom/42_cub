/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map_ults.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/05 23:21:43 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	get_valid_line(char **dst, int fd)
{
	*dst = get_next_line(fd);
	if (*dst == NULL)
		return (FALSE);
	return (TRUE);
}

void	remove_char_of_player(t_map *data)
{
	int	posi_y;
	int	posi_x;

	posi_y = (int)data->player[P_Y];
	posi_x = (int)data->player[P_X];
	data->mini_map[posi_y][posi_x] = '0';
	debug_printc(has_flag(), "Removing char map: ", "OK\n");
}

t_bool	check_parameters(t_map *data, int fd)
{
	if (data == NULL)
		return (FALSE);
	if (fd < 0)
		return (FALSE);
	return (TRUE);
}
