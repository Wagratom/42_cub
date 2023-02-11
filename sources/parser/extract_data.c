/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 13:48:50 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	clear_texture(t_parse *data, t_bool	status)
{
	int	index;

	index = -1;
	while(++index < 4)
	{
		if (data->coordinates[index])
			free(data->coordinates[index]);
	}
	return (status);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	create_rgbf(t_data *data)
{
	int	f[3];

	f[0] = data->parser.f[0];
	f[1] = data->parser.f[1];
	f[2] = data->parser.f[2];
	data->map.f = create_trgb(1, f[0], f[1], f[2]);
}

void	create_rgbc(t_data *data)
{
	int	c[3];

	c[0] = data->parser.c[0];
	c[1] = data->parser.c[1];
	c[2] = data->parser.c[2];
	data->map.c = create_trgb(1, c[0], c[1], c[2]);
}

t_bool	extract_data_status(t_data *data, int fd)
{
	if (data == NULL || fd < 0)
		return (FALSE);
	if (extract_data_map(&data->parser, fd) == -1)
		return (clear_texture(&data->parser, FALSE));
	if (!all_coordinates_valid(&data->parser))
		return (clear_texture(&data->parser, FALSE));
	if (!init_texture(data))
		return (clear_texture(&data->parser, FALSE));
	create_rgbf(data);
	create_rgbc(data);
	return clear_texture(&data->parser, TRUE);
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
