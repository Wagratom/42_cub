/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:52:13 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/13 14:07:02 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// static	void	map_debug(char **map, t_bool status)
// {
// 	if (!has_flag())
// 		return ;
// 	usleep(50000);
// 	draw_mapingd(map);
// 	printf("status = %d\n", status);
// }

t_bool	verify_is_closed(char **map, int y, int x)
{
	static t_bool status = TRUE;

	// map_debug(map, status);
	if (!verify_not_close(map, x, y, &status))
		return (status);
	map[y][x] = '4';
	if (val_move_right(map, &x, y))
		verify_is_closed(map, y, x);
	else if (val_move_down(map, x, &y, &status))
		verify_is_closed(map, y, x);
	else if (val_move_left(map, &x, y, &status))
		verify_is_closed(map, y, x);
	else if (val_move_up(map, x, &y, &status))
		verify_is_closed(map, y, x);
	else
		return (status);
	verify_is_closed(map, y, x);
	return (status);
}

t_bool	verify_exit_status(t_map *data)
{
	t_bool	status;
	char	**copy_map;

	if (data->mini_map == NULL)
		return (msg_and_error(NULL, "Error: mini map is null\n"));
	status = TRUE;
	copy_map = ft_array_dup(data->mini_map);
	status = verify_is_closed(copy_map, data->player[P_Y], data->player[P_X]);
	delete_map(copy_map);
	if (!status)
		return (msg_and_error("Error: ", "Maping not closed"));
	debug_printc(has_flag(), "validacion: ", "Exit OK");
	return (status);
}
