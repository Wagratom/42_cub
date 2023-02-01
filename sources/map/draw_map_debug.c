/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/01 13:34:27 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_mapingD(char **map)
{
	if (map == NULL)
		return ;
	debug_printC(has_flag(), NULL, "\tMap allocated\n");
	while (*map)
	{
		printf("%s", *map);
		map++;
	}
	printf("\n");
}
