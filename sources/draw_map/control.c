/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:32:20 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 10:23:37 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	player_p_x(t_data *data)
{
	return (data->map.player[P_X]);
}

double	player_p_y(t_data *data)
{
	return (data->map.player[P_Y]);
}
