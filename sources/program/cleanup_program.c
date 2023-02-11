/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:59:13 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 10:15:50 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	exit_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void	clean_connections(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	delete_map(char **map)
{
	int	index;

	if (map == NULL || *map == NULL)
		return ;
	index = -1;
	while (map[++index])
		free(map[index]);
	free(map);
	map = NULL;
}

int	cleanup_program(t_data *data)
{
	clean_connections(data);
	delete_map(data->map.full_map);
	exit(0);
	return (0);
}
