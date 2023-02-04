/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_ults.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/04 11:43:00 by wwalas-          ###   ########.fr       */
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

void	interact_size_d_map(t_map *data)
{
	data->size_d_map += 1;
}
