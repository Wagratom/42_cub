/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:05 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 18:28:49 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	init_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 640, 480, "Cub3D");
	if (data->win == NULL)
	{
		printf("Erro creat windows");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_windows_or_die(t_data *data)
{
	debug_print(has_flag(), "\tInitializing Windowns\n");
	if (data->mlx == NULL)
	{
		printf("Not creat windows, mlx pointer null");
		return (FALSE);
	}
	if (init_windows(data) == FALSE)
		return (FALSE);
	debug_print(has_flag(), "Windowns: Ok\n");
	return (TRUE);
}
