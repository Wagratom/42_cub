/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_ults.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 13:31:28 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*data_in_line(char *line)
{
	int		init_data_or_die;
	int		end_data;

	if (line == NULL || *line == '\0')
		return (NULL);
	init_data_or_die = (ft_strchr(line, ' ') + 1) - line;
	end_data = (ft_strchr(line, '\n') - line) - init_data_or_die;
	return (ft_substr(line, init_data_or_die, end_data));
}

char	*get_line_p(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

void	interact_size_d_map(t_parse *data)
{
	data->size_parser += 1;
}

t_bool	all_coordinates_valid(t_parse *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->coordinates[i] == NULL)
			return (msg_and_error("Error: ", "Some coordinate did not pass"));
	}
	return (TRUE);
}
