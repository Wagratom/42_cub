/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 14:14:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	
t_bool	alloc_texture(t_map *data)
{
	int	index;
	int	size;

	size = sizeof(int) * TILE_SIZE * TILE_SIZE;
	data->texture = (int **)malloc(sizeof(int *) * 4);
	if (!data->texture)
		return (msg_and_error(NULL, "Error: Error in malloc pointer to texture"));
	index = -1;
	while (++index < 4)
	{
		data->texture[index] = (int *)malloc(size);
		if (!data->texture[index])
			return (msg_and_error(NULL, "Error: Error in malloc pointer to texture"));
		ft_bzero(data->texture[index], size); // nao sei c da o msm efeito // pode usar o ft_calloc tb da na mesma
	}
	return (TRUE);
}

static t_bool	clear_texture(t_map *data)
{
	int	index;

	index = -1;
	while(++index < 4)
		free(data->texture[index]);
	free(data->texture);
	return (FALSE);
}

t_bool	create_texture(t_data *data)
{
	int	index;
	t_map	*map;

	debug_printc(has_flag(), NULL, "allocando a pointers to texture: OK");
	map = &data->map;
	if (!alloc_texture(map))
		return (FALSE);
	index = -1;
	while (++index < 4)
	{
		if (load_texture(data, map->texture[index], data->parser.coordinates[index]))
			continue;
		clear_texture(map);
		return (msg_and_error("Error: ", "Not load texture"));
	}
	debug_printc(has_flag(), NULL, "Texture: Ok\n");
	return (TRUE);
}
