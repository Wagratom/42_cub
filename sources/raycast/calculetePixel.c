/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculetePixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:47:41 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/06 17:50:02 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//	calculate lowest and highest pixel to fill in current stripe

void	calculate_pixel(t_raycast *itens)
{
	if (itens->drawStart < 0)
		itens->drawStart = 0;
	itens->drawEnd = itens->lineHeight / 2 + HEIGHT / 2;
	if (itens->drawEnd >= HEIGHT)
		itens->drawEnd = HEIGHT - 1;
}
