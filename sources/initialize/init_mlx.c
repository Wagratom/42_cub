/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 10:24:46 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	init_mlx_or_die(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		printf("Error: Not init mlx");
		return (FALSE);
	}
	return (TRUE);
}
