/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/05 23:39:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	val_move_right(char **map, int *posi_x, int posi_y)
{
	if (map[posi_y][*posi_x + 1] == '1' || map[posi_y][*posi_x + 1] == '4')
		return (FALSE);
	*posi_x += 1;
	return (TRUE);
}

t_bool	val_move_down(char **map, int posi_x, int *posi_y)
{
	if (map[*posi_y + 1] == NULL)
		return (FALSE);
	if (map[*posi_y + 1][posi_x] == '1' || map[*posi_y + 1][posi_x] == '4')
		return (FALSE);
	*posi_y += 1;
	return (TRUE);
}

t_bool	val_move_left(char **map, int *posi_x, int posi_y)
{
	if (*posi_x - 1 < 0)
		return (FALSE);
	if (map[posi_y][*posi_x - 1] == '1' || map[posi_y][*posi_x - 1] == '4')
		return (FALSE);
	*posi_x -= 1;
	return (TRUE);
}

t_bool	val_move_up(char **map, int posi_x, int *posi_y)
{
	if (*posi_y - 1 < 0)
		return (FALSE);
	if (map[*posi_y - 1][posi_x] == '1' || map[*posi_y - 1][posi_x] == '4')
		return (FALSE);
	*posi_y -= 1;
	return (TRUE);
}

t_bool	verify_not_close(char **map, int x, int y, t_bool *status)
{
	if (map == NULL || *map == FALSE)
		return (FALSE);
	if (map[y][x] == ' ')
		*status = (FALSE);
	if (map[y][x] == '\n')
		*status = (FALSE);
	return (*status);
}