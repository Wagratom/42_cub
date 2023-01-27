/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 22:14:02 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	val_move_right(char **map, int *posi_x, int posi_y)
{
	if (map[posi_y][*posi_x + 1] == '1' || map[posi_y][*posi_x + 1] == '4')
		return (FALSE);
	*posi_x += 1;
	return (TRUE);
}

static t_bool	val_move_down(char **map, int posi_x, int *posi_y)
{
	if (map[*posi_y + 1] == NULL)
		return (FALSE);
	if (map[*posi_y + 1][posi_x] == '1' || map[*posi_y + 1][posi_x] == '4')
		return (FALSE);
	*posi_y += 1;
	return (TRUE);
}

static t_bool	val_move_left(char **map, int *posi_x, int posi_y)
{
	if (*posi_x - 1 < 0)
		return (FALSE);
	if (map[posi_y][*posi_x - 1] == '1' || map[posi_y][*posi_x - 1] == '4')
		return (FALSE);
	*posi_x -= 1;
	return (TRUE);
}

static t_bool	val_move_up(char **map, int posi_x, int *posi_y)
{
	if (*posi_y - 1 < 0)
		return (FALSE);
	if (map[*posi_y - 1][posi_x] == '1' || map[*posi_y - 1][posi_x] == '4')
		return (FALSE);
	*posi_y -= 1;
	return (TRUE);
}

static t_bool	verify_not_close(char **map, int posi_x, int posi_y, t_bool *status)
{
	if (map[posi_y][posi_x] == ' ')
		*status = FALSE;
	if (map[posi_y][posi_x] == '\n')
		*status = FALSE;
	return (*status);
}

void	verify_is_closed(char **map, int posi_x, int posi_y, t_bool *status)
{
	if (!verify_not_close(map, posi_x, posi_y, status))
		return ;
	//usleep(40000);
	map[posi_y][posi_x] = '4';
	//draw_map_debug(map->map);
	if (val_move_right(map, &posi_x, posi_y))
	{
		verify_is_closed(map, posi_x, posi_y, status);
	}
	else if (val_move_down(map, posi_x, &posi_y))
	{
		verify_is_closed(map, posi_x, posi_y, status);
	}
	else if (val_move_left(map, &posi_x, posi_y))
	{
		verify_is_closed(map, posi_x, posi_y, status);
	}
	else if (val_move_up(map, posi_x, &posi_y))
	{
		verify_is_closed(map, posi_x, posi_y, status);
	}
	else
		return ;
	verify_is_closed(map, posi_x, posi_y, status);
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
	verify_is_closed(copy_map, data->player[P_X], data->player[P_Y], &status);
	delete_map(copy_map);
	printf("map OK...\n");
	return (status);
}
