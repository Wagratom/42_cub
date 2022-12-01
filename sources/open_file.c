/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:30:29 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/30 18:39:09 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>

t_bool	open_file(t_data *data, char *file_name)
{
	int	fd;

	data->map.fd = open(file_name, O_RDONLY);
	if (data->map.fd >= 0)
		return (TRUE);
	// perror
	return (FALSE);
}
