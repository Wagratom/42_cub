/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:13:43 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/05 23:26:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	extracting_date(t_map *data)
{
	debug_printc(has_flag(), C, "\tExtract data of map...");
	if (!open_file_status(&data->fd, data->file_name))
		return (FALSE);
	if (!extract_data_status(data, data->fd))
		return (FALSE);
	return (TRUE);
}

static t_bool	valid_map_chars(t_map *data)
{
	debug_printc(has_flag(), C, "\tValiding chars of map...");
	if (!valid_chars_or_die(data))
		return (FALSE);
	close(data->fd);
	debug_printc(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

static t_bool	locating_map(t_map *data)
{
	debug_printc(has_flag(), C, "\tallocating the map");
	if (!open_file_status(&data->fd, data->file_name))
		return (FALSE);
	if (!alloc_map_status(data, data->fd))
		return (FALSE);
	close(data->fd);
	return (TRUE);
}

static t_bool	valid_map_exit(t_map *data)
{
	debug_printc(has_flag(), C, "\tValidating map exit...");
	if (!verify_exit_status(data))
		return (FALSE);
	return (TRUE);
}

t_bool	manipulating_map(t_data *data)
{
	if (!extracting_date(&data->map))
		cleanup_program(data);
	if (!valid_map_chars(&data->map))
		cleanup_program(data);
	if (!locating_map(&data->map))
		cleanup_program(data);
	if (!valid_map_exit(&data->map))
		cleanup_program(data);
	debug_printc(has_flag(), "Validacion: ", "Map ok\n");
	return (TRUE);
}
