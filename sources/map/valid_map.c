/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:13:43 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 13:29:03 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_size_of_parser(t_data *data)
{
	data->map.size_parser = data->parser.size_parser;
}

static t_bool	extracting_date(t_data *data)
{
	t_map	*aux;

	aux = &data->map;
	debug_printc(has_flag(), C, "\tExtract data of map...");
	if (!open_file_status(&aux->fd, aux->file_name))
		return (FALSE);
	if (!extract_data_status(data, aux->fd))
		return (FALSE);
	set_size_of_parser(data);
	return (TRUE);
}

static t_bool	valid_map_chars(t_data *data)
{
	debug_printc(has_flag(), C, "\tValiding chars of map...");
	if (!valid_chars_or_die(&data->map))
		return (FALSE);
	close(data->map.fd);
	debug_printc(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

static t_bool	locating_map(t_data *data)
{
	debug_printc(has_flag(), C, "\tallocating the map");
	if (!open_file_status(&data->map.fd, data->map.file_name))
		return (FALSE);
	if (!alloc_map_status(&data->map, data->map.fd))
		return (FALSE);
	close(data->map.fd);
	return (TRUE);
}

static t_bool	valid_map_exit(t_data *data)
{
	debug_printc(has_flag(), C, "\tValidating map exit...");
	return (verify_exit_status(&data->map));
}

t_bool	manipulating_map(t_data *data)
{
	if (!extracting_date(data))
		cleanup_program(data);
	if (!valid_map_chars(data))
		cleanup_program(data);
	if (!locating_map(data))
		cleanup_program(data);
	if (!valid_map_exit(data))
		cleanup_program(data);
	debug_printc(has_flag(), "Validacion: ", "Map ok\n");
	return (TRUE);
}
