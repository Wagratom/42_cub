/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 14:22:01 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*data_in_line(char *str)
{
	char	*result;
	int		init_data;
	int		end_data;

	if (str == NULL || *str == '\0')
		return (NULL);
	init_data = (ft_strchr(str, ' ') + 1) - str;
	end_data = (ft_strchr(str, '\n') - str) - init_data;
	return (ft_substr(str, init_data, end_data));
}

int	open_file_is_clear_path(int *dst, char *path_file)
{
	debug_printC(has_flag(), "Opening texture path: ", path_file);
	*dst =  open(path_file, O_RDONLY, 0777);
	free(path_file);
	if (*dst >= 0)
		return (1);
	debug_printC(has_flag(), NULL, "Error in oping texture");
	perror("");
	return (-1);
}

t_bool	extract_data_status(t_parse *data, char **full_map)
{
	int		index;
	int		status;

	index = -1;
	while (full_map[++index])
	{
		if (full_map[index][0] == '\n')
			continue;
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

t_bool	extract_data(t_parse *data, char **full_map)
{
	int		status;
	int		index;

	if (full_map == NULL || *full_map == NULL)
		return (FALSE);
	if (data == NULL)
		return (FALSE);
	return (extract_data_status(data, full_map));
}