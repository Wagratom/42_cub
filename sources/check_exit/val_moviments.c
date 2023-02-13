/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_moviments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 11:45:15 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	set_status_to_false(t_bool *status)
{
	*status = FALSE;
	return (FALSE);
}

t_bool	val_move_right(char **map, int *posi_x, int posi_y)
{
	if (map == NULL)
		return (FALSE);
	if (map[posi_y][*posi_x + 1] == '1' || map[posi_y][*posi_x + 1] == '4')
		return (FALSE);
	*posi_x += 1;
	return (TRUE);
}

t_bool	val_move_down(char **map, int posi_x, int *posi_y, t_bool *status)
{
	if (ft_strlen(map[*posi_y + 1]) < (size_t)posi_x)
		return (set_status_to_false(status));
	if (map[*posi_y + 1][posi_x] == '1' || map[*posi_y + 1][posi_x] == '4')
		return (FALSE);
	*posi_y += 1;
	return (TRUE);
}

t_bool	val_move_left(char **map, int *posi_x, int posi_y, t_bool *status)
{
	if (map == NULL)
		return (FALSE);
	if (*posi_x - 1 < 0)
		return (set_status_to_false(status));
	if (map[posi_y][*posi_x - 1] == '1' || map[posi_y][*posi_x - 1] == '4')
		return (FALSE);
	*posi_x -= 1;
	return (TRUE);
}

t_bool	val_move_up(char **map, int posi_x, int *posi_y, t_bool *status)
{
	if (*posi_y - 1 < 0)
		return (set_status_to_false(status));
	if (ft_strlen(map[*posi_y - 1]) < (size_t)posi_x)
		return (set_status_to_false(status));
	if (map[*posi_y - 1][posi_x] == '1' || map[*posi_y - 1][posi_x] == '4')
		return (FALSE);
	*posi_y -= 1;
	return (TRUE);
}
