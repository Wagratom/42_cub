/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:28:22 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:11:53 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	valid_map_chars(t_map *data)
{
	if (open_file_or_die(data) == FALSE)
		return (FALSE);
	if (valid_chars_or_die(data) == FALSE)
		return (FALSE);
	close(data->fd);
	debug_print(has_flag(), "Validacion Chars: Ok\n\n");
	return (TRUE);
}

static t_bool	valid_map_exit(t_map *data)
{
	if (open_file_or_die(data) == FALSE)
		return (FALSE);
	if (alloc_map_status(data) == FALSE)
		return (FALSE);
	if (verify_exit_or_die(data) == FALSE)
		return (FALSE);
	close(data->fd);
	debug_print(has_flag(), "Validacion Exit: Ok\n\n");
	return (TRUE);
}

t_bool	valid_map(t_data *data)
{
	debug_print(has_flag(), "\tValiding map...\n");
	if (valid_map_chars(&data->map) == FALSE)
		cleanup_program(data);
	if (valid_map_exit(&data->map) == FALSE)
		cleanup_program(data);
	debug_print(has_flag(), "Map ok\n\n");
	return (TRUE);

}
