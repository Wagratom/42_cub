/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 12:06:02 by wwalas-          ###   ########.fr       */
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

int	save_textured_path(t_parse *data, int coordinate, char *path_file)
{
	if (coordinate == -1)
		return (NOT_COMPATIBLE);
	if (data->coordinates[coordinate] != NULL)
	{
		msg_and_error("Error: ", "Some coordinate is wrong");
		return (INVALID_DATA);
	}
	data->coordinates[coordinate] = path_file;
	return (NEW_LINE);
}

int	open_texture(t_parse *data, int coordinates, char *path_file)
{
	int	status;

	status = save_textured_path(data, coordinates - 1, path_file);
	if (status != NEW_LINE)
		free(path_file);
	debug_printi(has_flag(), "Coordinates: ", coordinates);
	return (status);
}
