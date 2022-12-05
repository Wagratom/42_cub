/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:30:29 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 22:47:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	open_file(t_map *data)
{
	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd < 0)
		return (FALSE);
	return (TRUE);
}

t_bool	open_file_or_die(t_map *data)
{
	if (open_file(data))
		return (TRUE);
	printf("Error: Not open file\n");	// perror with die
	return (FALSE);
}
