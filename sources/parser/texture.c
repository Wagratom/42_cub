/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 14:16:38 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	coordinates(char *line)
{
	debug_printC(has_flag(), "\tGet line texture: ", line);
	if (compare_strings(first_word(line), "NO"))
		return (1);
	else if (compare_strings(first_word(line), "SO"))
		return (2);
	else if (compare_strings(first_word(line), "WE"))
		return (3);
	else if (compare_strings(first_word(line), "EA"))
		return (4);
	return (0);
}

int	open_texture(int coordinates, char *path_file, t_parse *data)
{
	debug_printI(has_flag(), "Coordinates: ", coordinates);
	if (coordinates == 0)
		return (0);
	if (coordinates == 1)
		return (open_file_is_clear_path(&data->north, path_file));
	if (coordinates == 2)
		return (open_file_is_clear_path(&data->south, path_file));
	if (coordinates == 3)
		return (open_file_is_clear_path(&data->west, path_file));
	if (coordinates == 4)
		return (open_file_is_clear_path(&data->east, path_file));
	return (1);
}