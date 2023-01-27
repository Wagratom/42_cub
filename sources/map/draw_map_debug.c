/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:15 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:14:06 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_mapingD(char **map)
{
	debug_print(has_flag(), "\tMap allocated\n\n");
	while (*map)
	{
		printf("%s", *map);
		map++;
	}
	printf("\n");
}
