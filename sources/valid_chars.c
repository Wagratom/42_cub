/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/01 11:38:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_line(char **line, int file)
{
	free(*line);
	*line = get_next_line(file);
	return (*line);
}

void	interactor_chars(t_data *data, char c)
{
	data->map.chars[P_W] += (c == 'W');
	data->map.chars[P_S] += (c == 'S');
	data->map.chars[P_N] += (c == 'N');
	data->map.chars[P_E] += (c == 'E');
}

t_bool	valid_interactor(t_data *data)
{
	int	total;

	total = 0;
	total += data->map.chars[P_W];
	total += data->map.chars[P_S];
	total += data->map.chars[P_N];
	total += data->map.chars[P_E];
	if (total == 1)
		return (TRUE);
	//die program
	return (FALSE);
}

t_bool	valid_chars_line(t_data *data, char *line)
{
	int	index;

	index = -1;
	while (line[++index])
	{
		if (ft_strchr(VALID_CHARS, line[index]))
			continue ;
		//die program
		return (FALSE);
	}
	return (TRUE);
}

t_bool	valid_chars(t_data *data, int file)
{
	char	*line;

	line == NULL;
	while(get_line(&line, file))
		valid_chars_line(data, line);
	valid_interactor(data);
}
