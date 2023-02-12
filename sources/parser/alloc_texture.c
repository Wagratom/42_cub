/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:35:37 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 23:15:32 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	alloc_texture(t_map *data)
{
	int	index;
	int	size;

	size = sizeof(int) * TILE_SIZE * TILE_SIZE;
	data->texture = (int **)malloc(sizeof(int *) * 4);
	if (!data->texture)
		return (msg_and_error(NULL, "Error: malloc pointer to texture"));
	index = -1;
	while (++index < 4)
	{
		data->texture[index] = (int *)malloc(size);
		if (!data->texture[index])
			return (msg_and_error(NULL, "Error: malloc pointer to texture"));
		ft_bzero(data->texture[index], size);
	}
	return (TRUE);
}

t_bool	create_texture(t_data *data)
{
	int		i;
	t_map	*map;

	debug_printc(has_flag(), NULL, "pointers to texture: OK");
	map = &data->map;
	if (!alloc_texture(map))
		return (FALSE);
	i = -1;
	while (++i < 4)
	{
		if (load_texture(data, map->texture[i], data->parser.coordinates[i]))
			continue ;
		return (msg_and_error("Error: ", "Not load texture"));
	}
	debug_printc(has_flag(), NULL, "Texture: Ok\n");
	return (TRUE);
}
