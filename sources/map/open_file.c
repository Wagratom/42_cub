/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:30:29 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/31 15:09:49 by wwalas-          ###   ########.fr       */
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

t_bool	open_file_status(t_map *data)
{
	if (open_file(data))
		return (TRUE);
	perror("");
	return (FALSE);
}
