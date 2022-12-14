/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 17:18:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	val_move_right(char **map, int *position_x, int position_y)
{
	if (map[position_y][*position_x + 1] == '1' || map[position_y][*position_x + 1] == '4')
		return (FALSE);
	*position_x += 1;
	return (TRUE);
}

static t_bool	val_move_down(char **map, int position_x, int *position_y)
{
	if (map[*position_y + 1] == NULL)
		return (FALSE);
	if (map[*position_y + 1][position_x] == '1' || map[*position_y + 1][position_x] == '4')
		return (FALSE);
	*position_y += 1;
	return (TRUE);
}

static t_bool	val_move_left(char **map, int *position_x, int position_y)
{
	if (*position_x - 1 < 0)
		return (FALSE);
	if (map[position_y][*position_x - 1] == '1' || map[position_y][*position_x - 1] == '4')
		return (FALSE);
	*position_x -= 1;
	return (TRUE);
}

static t_bool	val_move_up(char **map, int position_x, int *position_y)
{
	if (*position_y - 1 < 0)
		return (FALSE);
	if (map[*position_y - 1][position_x] == '1' || map[*position_y - 1][position_x] == '4')
		return (FALSE);
	*position_y -= 1;
	return (TRUE);
}

static t_bool	verify_not_close(char **map, int position_x, int position_y, t_bool *status)
{
	if (map[position_y][position_x] == ' ')
		*status = FALSE;
	if (map[position_y][position_x] == '\n')
		*status = FALSE;
	return (*status);
}

void	verify_is_closed(char **map, int position_x, int position_y, t_bool *status)
{
	if (!verify_not_close(map, position_x, position_y, status))
		return ;
	//usleep(40000);
	map[position_y][position_x] = '4';
	//draw_map_debug(map->map);
	if (val_move_right(map, &position_x, position_y))
	{
		verify_is_closed(map, position_x, position_y, status);
	}
	else if (val_move_down(map, position_x, &position_y))
	{
		verify_is_closed(map, position_x, position_y, status);
	}
	else if (val_move_left(map, &position_x, position_y))
	{
		verify_is_closed(map, position_x, position_y, status);
	}
	else if (val_move_up(map, position_x, &position_y))
	{
		verify_is_closed(map, position_x, position_y, status);
	}
	else
		return ;
	verify_is_closed(map, position_x, position_y, status);
}

t_bool	verify_exit_or_die(t_map *data)
{
	t_bool	status;
	char	**copy_map;

	if (data->map == NULL)
		return (FALSE);
	status = TRUE;
	copy_map = ft_array_dup(data->map);
	printf("validando mapa...\n");
	verify_is_closed(copy_map, data->p_player[P_X], data->p_player[P_Y], &status);
	delete_map(copy_map);
	printf("map OK...\n");
	return (status);
}
