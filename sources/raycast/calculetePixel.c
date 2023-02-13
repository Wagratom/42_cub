/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculetePixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:47:41 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 23:49:16 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//	calculate lowest and highest pixel to fill in current stripe

void	calculate_pixel(t_raycast *itens)
{
	if (itens->d_start < 0)
		itens->d_start = 0;
	itens->d_end = itens->l_height / 2 + HEIGHT / 2;
	if (itens->d_end >= HEIGHT)
		itens->d_end = HEIGHT - 1;
}
