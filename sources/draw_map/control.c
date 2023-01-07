/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:32:20 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/07 13:04:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	player_posX(t_data *data)
{
	return (data->map.p_player[P_X]);
}

double	player_posY(t_data *data)
{
	return (data->map.p_player[P_Y]);
}
