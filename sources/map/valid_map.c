/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:28:22 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/25 12:01:17 by wwalas-          ###   ########.fr       */
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
	return (TRUE);
}

static t_bool	valid_map_exit(t_map *data)
{
	if (open_file_or_die(data) == FALSE)
		return (FALSE);
	alloc_map_or_die(data);
	verify_exit_or_die(data);
	close(data->fd);
}

t_bool	valid_map(t_data *data)
{
	if (valid_map_chars(&data->map) == FALSE)
		cleanup_program(data);
	if (valid_map_exit(&data->map) == FALSE)
		cleanup_program(data);
	return (TRUE);

}
