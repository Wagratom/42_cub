/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 10:40:27 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*data_in_line(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);
	return ((ft_strchr(str, ' ') + 1));
}

int	open_file_parser(int *dst, char *path_file)
{
	*dst =  open(path_file, O_RDONLY);
	if (*dst >= 0)
		return (0);
	debug_print(has_flag(), "Error in oping file in path\n", path_file);
	perror("");
	return (-1);
}

t_bool	extract_data(t_parse *data, char **full_map)
{
	int		status;
	int		index;

	index = -1;
	while (full_map[++index])
	{
		status = open_texture(coordinates(full_map[index]), data_in_line(full_map[index]), data);
		if (status == -1)
			return (FALSE);
		if (status == 1)
			continue;
		status = fill_collor(collor_rgb(full_map[index]), data_in_line(full_map[index]), data);
		if (status == -1)
			return (FALSE);
		if (status == 1)
			continue;
		break ;
	}
}
