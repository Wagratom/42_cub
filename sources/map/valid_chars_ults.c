/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:24:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 17:49:40 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	is_special_char(char _char)
{
	if (ft_strchr(ESPECIAL_CHARS, _char))
		return (TRUE);
	return (FALSE);
}

void	set_proportions_map(t_map *data, int size_x)
{
	data->size_y += 1;
	if (size_x > data->size_x)
		data->size_x = size_x;
}

char	*get_line(t_map *data, char **line)
{
	free(*line);
	*line = get_next_line(data->fd);
	set_proportions_map(data, ft_strlen(*line));
	return (*line);
}

t_bool	valid_char_or_die(char _char)
{
	if (ft_strchr(VALID_CHARS, _char))
		return (TRUE);
	write(2, "Error: Invalid line\n", 20);
	return (FALSE);
}

t_bool	set_direction_player(t_map *data, char _char)
{
	if (!is_special_char(_char))
		return (msg_and_error("Error: direction_p: ", "Non-special character"));
	if (_char == 'N')
	{
		data->dir[P_Y] = -1;
		data->plane[P_X] = 0.66;
	}
	else if (_char == 'S')
	{
		data->dir[P_Y] = 1;
		data->plane[P_X] = -0.66;
	}
	else if (_char == 'E')
	{
		data->dir[P_X] = 1;
		data->plane[P_Y] = 0.66;
	}
	else if (_char == 'W')
	{
		data->dir[P_X] = -1;
		data->plane[P_Y] = -0.66;
	}
	return (TRUE);
}
