/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/02 10:37:23 by wwallas-         ###   ########.fr       */
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

t_bool	interactor_chars(t_data *data, char c)
{
	static validator = 0;

	if (c == '0' || c == '1' || c == '\n')
		return (FALSE);
	if (validator > 0)
		return (FALSE);
		//die_program
	data->map.chars[P_W] += (c == 'W');
	data->map.chars[P_S] += (c == 'S');
	data->map.chars[P_N] += (c == 'N');
	data->map.chars[P_E] += (c == 'E');
	validator++;
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
