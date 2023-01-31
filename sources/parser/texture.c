/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 15:55:05 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	coordinates(char *line)
{
	if (compare_strings(first_word(line), "NO"))
		return (1);
	else if (compare_strings(first_word(line), "SO"))
		return (2);
	else if (compare_strings(first_word(line), "WE"))
		return (3);
	else if (compare_strings(first_word(line), "AE"))
		return (4);
	return (0);
}

int	open_texture(int coordinates, char *path_file, t_parser *data)
{
	if (coordinates == 0)
		return (0);
	if (coordinates == 1)
		return (open_file_parser(&data->north, path_file));
	if (coordinates == 2)
		return (open_file_parser(&data->south, path_file));
	if (coordinates == 3)
		return (open_file_parser(&data->west, path_file));
	if (coordinates == 4)
		return (open_file_parser(&data->east, path_file));
	return (1);
}
