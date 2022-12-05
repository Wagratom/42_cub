/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:04:05 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/16 16:22:36 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	init_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 1000, 1000, "Cub3D");
	if (data->win == NULL)
	{
		die_program_msg("Erro creat windows");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_windows_or_die(t_data *data)
{
	if (data->mlx == NULL)
	{
		die_program_msg("Not creat windows, mlx pointer null");
		return (FALSE);
	}
	return (init_windows(data));
}
