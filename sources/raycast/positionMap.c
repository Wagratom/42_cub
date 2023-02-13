/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 20:30:51 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	position_player_map(t_raycast *itens, t_data *data)
{
	itens->map[P_X] = (int)player_p_x(data);
	itens->map[P_Y] = (int)player_p_y(data);
}
