/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/12 15:20:01 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	clear_texture(t_parse *data, t_bool	status)
{
	int	index;

	index = -1;
	while (++index < 4)
	{
		if (data->coordinates[index])
			free(data->coordinates[index]);
	}
	if (data->texture)
		free(data->texture);
	return (status);
}

int	extract_data_line(t_parse *data, char *line)
{
	int		status;

	if (*line == '\n')
		return (NEW_LINE);
	status = open_texture(data, coordinates(line), data_in_line(line));
	if (status != NOT_COMPATIBLE)
		return (status);
	status = fill_collor(data, collor_rgb(line), data_in_line(line));
	if (status == NOT_COMPATIBLE)
		return (END_READ);
	return (status);
}

int	extract_data_map(t_parse *parser, int fd)
{
	char	*line;
	int		status;

	while (get_line_p(&line, fd))
	{
		status = extract_data_line(parser, line);
		debug_printi(has_flag(), "status = ", status);
		free(line);
		if (status == INVALID_DATA)
			return (-1);
		if (status == END_READ)
			break ;
		interact_size_d_map(parser);
	}
	return (0);
}

t_bool	extract_data_status(t_data *data, int fd)
{
	if (data == NULL || fd < 0)
		return (FALSE);
	if (extract_data_map(&data->parser, fd) == -1)
		return (clear_texture(&data->parser, FALSE));
	if (!all_coordinates_valid(&data->parser))
		return (clear_texture(&data->parser, FALSE));
	if (!create_texture(data))
		return (clear_texture(&data->parser, FALSE));
	if (!create_rgbs(data))
		return (clear_texture(&data->parser, FALSE));
	return (clear_texture(&data->parser, TRUE));
}
