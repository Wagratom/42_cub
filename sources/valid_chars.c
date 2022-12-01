/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/01 13:17:08 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_line(t_data *data, char **line)
{
	free(*line);
	*line = get_next_line(data->map.fd);
	data->map.size_y++;
	return (*line);
}

void	save_position_player(t_data *data, int x, char c)
{
	if (c == '0' || c == '1' || c == '\n')
		return ;
	data->map.p_player[P_X] = x;
	data->map.p_player[P_Y] = data->map.size_y;
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
		if (!ft_strchr(VALID_CHARS, line[index]))
			return (FALSE);
		interactor_chars(data, line[index]);
		save_position_player(data, index, line[index]);
		//die program
	}
	return (TRUE);
}

t_bool	valid_chars(t_data *data, int file)
{
	char	*line;

	line == NULL;
	while(get_line(data, &line))
		valid_chars_line(data, line);
	valid_interactor(data);
}
