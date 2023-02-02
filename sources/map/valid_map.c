/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:28:22 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/02 00:01:35 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	valid_map_chars(t_map *data)
{
	if (open_file_status(data) == FALSE)
		return (FALSE);
	if (valid_chars_or_die(data) == FALSE)
		return (FALSE);
	close(data->fd);
	debug_printC(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

static t_bool	valid_map_exit(t_map *data)
{
	if (open_file_status(data) == FALSE)
		return (FALSE);
	if (alloc_map_status(data) == FALSE)
		return (FALSE);
	if (verify_exit_status(data) == FALSE)
		return (FALSE);
	close(data->fd);
	return (TRUE);
}

t_bool	valid_map(t_data *data)
{
	debug_printC(has_flag(), NULL, "\tValiding map...");
	if (valid_map_chars(&data->map) == FALSE)
		cleanup_program(data);
	if (valid_map_exit(&data->map) == FALSE)
		cleanup_program(data);
	debug_printC(has_flag(), "Validacion: ", "Map ok\n");
	return (TRUE);

}
