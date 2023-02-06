/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/05 23:35:35 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	verify_is_closed(char **map, int y, int x, t_bool *status)
{
	if (!verify_not_close(map, x, y, status))
		return ;
	map[y][x] = '4';
	if (val_move_right(map, &x, y))
		verify_is_closed(map, y, x, status);
	else if (val_move_down(map, x, &y))
		verify_is_closed(map, y, x, status);
	else if (val_move_left(map, &x, y))
		verify_is_closed(map, y, x, status);
	else if (val_move_up(map, x, &y))
		verify_is_closed(map, y, x, status);
	else
		return ;
	verify_is_closed(map, y, x, status);
}

t_bool	verify_exit_status(t_map *data)
{
	t_bool	status;
	char	**copy_map;

	if (data->mini_map == NULL)
		return (write_msg_error(NULL, "Error: mini map is null\n"));
	status = TRUE;
	copy_map = ft_array_dup(data->mini_map);
	verify_is_closed(copy_map, data->player[P_Y], data->player[P_X], &status);
	delete_map(copy_map);
	debug_printc(has_flag(), "validacion: ", "Exit OK");
	return (status);
}
