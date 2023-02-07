/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:05 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 14:45:46 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	init_windows(t_data *data)
{
	if (data->mlx == NULL)
		return (msg_and_error(NULL, "Not creat windows, mlx pointer null"));
	data->win = mlx_new_window(data->mlx, 640, 480, "Cub3D");
	if (data->win == NULL)
		return (msg_and_error(NULL, "Erro creat windows"));
	return (TRUE);
}

t_bool	init_windows_or_die(t_data *data)
{
	debug_printc(has_flag(), NULL, "\tInitializing Windowns\n");
	if (!init_windows(data))
		cleanup_program(data);
	debug_printc(has_flag(), "Windowns: ", "Ok");
	return (TRUE);
}
