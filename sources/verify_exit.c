/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 22:31:04 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	move_right(t_map *data, int *position_x, int position_y)
{
	if (data->map[position_y][*position_x + 1] == '1' || data->map[position_y][*position_x + 1] == '4')
		return (FALSE);
	*position_x += 1;
	return (TRUE);
}

t_bool	move_down(t_map *data, int position_x, int *position_y)
{
	if (data->map[*position_y + 1] == NULL)
		return (FALSE);
	if (data->map[*position_y + 1][position_x] == '1' || data->map[*position_y + 1][position_x] == '4')
		return (FALSE);
	*position_y += 1;
	return (TRUE);
}

t_bool	move_left(t_map *data, int *position_x, int position_y)
{
	if (*position_x - 1 < 0)
		return (FALSE);
	if (data->map[position_y][*position_x - 1] == '1' || data->map[position_y][*position_x - 1] == '4')
		return (FALSE);
	*position_x -= 1;
	return (TRUE);
}

t_bool	move_up(t_map *data, int position_x, int *position_y)
{
	if (*position_y - 1 < 0)
		return (FALSE);
	if (data->map[*position_y - 1][position_x] == '1' || data->map[*position_y - 1][position_x] == '4')
		return (FALSE);
	*position_y -= 1;
	return (TRUE);
}

t_bool	verify_not_close(t_map *data, int position_x, int position_y, int *status)
{
	if (data->map[position_y][position_x] == ' ')
		*status = 1;
	if (*status == 1)
		return (FALSE);
	return (TRUE);
}

void	verify_is_closed(t_map *data, int position_x, int position_y, int *status)
{
	if (!verify_not_close(data, position_x, position_y, status))
		return ;
	usleep(40000);
	printf("%d %d\n", position_y, position_x);
	data->map[position_y][position_x] = '4';
	draw_map(data->map);
	if (move_right(data, &position_x, position_y))
	{
		verify_is_closed(data, position_x, position_y, status);
	}
	else if (move_down(data, position_x, &position_y))
	{
		verify_is_closed(data, position_x, position_y, status);
	}
	else if (move_left(data, &position_x, position_y))
	{
		verify_is_closed(data, position_x, position_y, status);
	}
	else if (move_up(data, position_x, &position_y))
	{
		verify_is_closed(data, position_x, position_y, status);
	}
	else
		return ;
	verify_is_closed(data, position_x, position_y, status);
}

t_bool	verify_exit_or_die(t_map *data)
{
	int	status;

	if (data->map == NULL)
		return (FALSE);
	status = 0;
	printf("cheguei\n");
	verify_is_closed(data, data->p_player[P_X], data->p_player[P_Y], &status);
	if (status == 1)
		return (FALSE);
	return (TRUE);
}
