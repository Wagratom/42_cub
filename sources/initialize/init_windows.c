/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:05 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/31 10:39:24 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	init_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 1000, 1000, "Cub3D");
	if (data->win == NULL)
	{
		printf("Erro create windows"); //die
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_windows_or_die(t_data *data)
{
	if (data->mlx == NULL)
	{
		printf("Not create windows, mlx pointer null"); //die
		return (FALSE);
	}
	return (init_windows(data));
}
