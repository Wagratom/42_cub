/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/05 16:15:26 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	coordinates(char *line)
{
	debug_printc(has_flag(), "Get line texture: ", line);
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

void	save_textured_open(t_parse *data, int coordinate)
{
	if (coordinate == -1)
		return ;
	data->coordinates_save[coordinate] += 1;
}

int	open_texture(int coordinates, char *path_file, t_parse *data)
{
	int	status;

	status = NOT_COMPATIBLE;
	debug_printi(has_flag(), "Coordinates: ", coordinates);
	if (coordinates == 1)
		status = open_file_is_clear_path(&data->coordinites[NORTH], path_file);
	else if (coordinates == 2)
		status = open_file_is_clear_path(&data->coordinites[SOUTH], path_file);
	else if (coordinates == 3)
		status = open_file_is_clear_path(&data->coordinites[WEST], path_file);
	else if (coordinates == 4)
		status = open_file_is_clear_path(&data->coordinites[EAST], path_file);
	else
		status = NOT_COMPATIBLE;
	save_textured_open(data, coordinates - 1);
	free(path_file);
	return (status);
}
