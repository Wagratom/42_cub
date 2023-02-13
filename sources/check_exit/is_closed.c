/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_exit_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:14:13 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/13 11:46:36 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	verify_not_close(char **map, int x, int y, t_bool *status)
{
	if (map == NULL)
		return (FALSE);
	if (ft_strlen(map[y]) < (size_t)x)
		return (FALSE);
	if (map[y][x] == 0)
		return (FALSE);
	if (map[y][x] == ' ')
		*status = (FALSE);
	if (map[y][x] == '\n')
		*status = (FALSE);
	return (*status);
}
