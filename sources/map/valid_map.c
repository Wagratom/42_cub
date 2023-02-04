/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulating_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:28:22 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/02 16:36:45 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	extracting_date(t_map *data)
{
	if (!open_file_status(&data->fd, data->file_name))
		return (FALSE);
	if (!extract_data_status(data, data->fd))
		return (FALSE);
	return (TRUE);
}

static t_bool	valid_map_chars(t_map *data)
{
	if (!valid_chars_or_die(data))
		return (FALSE);
	close(data->fd);
	debug_printC(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

static t_bool	valid_map_exit(t_map *data)
{
	if (!open_file_status(&data->fd, data->file_name))
		return (FALSE);
	if (!alloc_map_status(data, data->fd))
		return (FALSE);
	if (!verify_exit_status(data))
		return (FALSE);
	printf("chegue aqui\n");
	close(data->fd);
	return (TRUE);
}

t_bool	manipulating_map(t_data *data)
{
	if (!extracting_date(&data->map))
		cleanup_program (data);
	if (!valid_map_chars(&data->map))
		cleanup_program(data);
	if (!valid_map_exit(&data->map))
		cleanup_program(data);
	debug_printC(has_flag(), "Validacion: ", "Map ok\n");
	return (TRUE);

}
