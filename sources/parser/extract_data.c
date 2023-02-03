/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/02 17:25:28 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*data_in_line(char *line)
{
	char	*result;
	int		init_data;
	int		end_data;

	if (line == NULL || *line == '\0')
		return (NULL);
	init_data = (ft_strchr(line, ' ') + 1) - line;
	end_data = (ft_strchr(line, '\n') - line) - init_data;
	return (ft_substr(line, init_data, end_data));
}

int	open_file_is_clear_path(int *dst, char *path_file)
{
	debug_printC(has_flag(), "Opening texture path: ", path_file);
	*dst =  open(path_file, O_RDONLY, 0777);
	if (*dst >= 0)
		return (NEW_LINE);
	debug_printC(has_flag(), NULL, "Error in oping texture");
	perror("");
	return (INVALID_DATA);
}

char	*get_line_p(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

/******************************************************************************/
/*								INIT										  */
/******************************************************************************/
t_bool	extract_data_status(t_map *data, int fd)
{
	int		status;
	int		size_end;

	debug_printC(has_flag(), NULL, "\tExtract data of map...");
	if (data == NULL || fd < 0)
		return (FALSE);
	size_end = extract_data_map(data, fd);
	if (size_end == -1)
		return (FALSE);
	return (TRUE);
}

void	interact_size_d_map(t_map *data)
{
	data->size_d_map += 1;
}

int	extract_data_map(t_map *data, int fd)
{
	char	*line;
	int		status;

	while (get_line_p(&line, fd))
	{
		status = extract_data_line(&data->d_map, line);
		debug_printI(has_flag(), "status = ", status);
		free(line);
		if (status == INVALID_DATA)
			return (-1);
		if (status == END_READ)
			break;
		interact_size_d_map(data);
	}
	return 0;
}

int	extract_data_line(t_parse *data, char *line)
{
	int		status;

	if (*line == '\n')
		return (NEW_LINE);
	status = open_texture(coordinates(line), data_in_line(line), data);
	if (status != NOT_COMPATIBLE)
		return (status);
	status = fill_collor(collor_rgb(line), data_in_line(line), data);
	if (status == NOT_COMPATIBLE)
		return (END_READ);
	return (status);
}
