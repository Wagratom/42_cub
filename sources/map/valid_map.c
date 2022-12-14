/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:28:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 22:51:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	valid_map_chars(t_map *data)
{
	open_file_or_die(data);
	valid_chars_or_die(data);
	close(data->fd);
}

static void	valid_map_exit(t_map *data)
{
	open_file_or_die(data);
	alloc_map_or_die(data);
	verify_exit_or_die(data);
	close(data->fd);
}

t_bool	valid_map(t_map *data)
{
	valid_map_chars(data);
	valid_map_exit(data);
	return (TRUE);

}
