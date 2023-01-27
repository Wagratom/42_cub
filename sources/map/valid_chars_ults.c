/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:24:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/27 13:16:22 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	proportions_map(t_map *data, int size_x)
{
	data->size_y += 1;
	if (size_x > data->size_x)
		data->size_x = size_x;
}

char	*get_line(t_map *data, char **line)
{
	free(*line);
	*line = get_next_line(data->fd);
	proportions_map(data, ft_strlen(*line));
	return (*line);
}

t_bool	valid_char_or_die(char _char)
{
	if (ft_strchr(VALID_CHARS, _char))
		return (TRUE);
	printf("invalid character \"%c\" ", _char);
	return (FALSE);
}

t_bool	interactor_chars(t_map *data, char _char)
{
	data->chars[P_W] += (_char == 'W');
	data->chars[P_S] += (_char == 'S');
	data->chars[P_N] += (_char == 'N');
	data->chars[P_E] += (_char == 'E');
}

t_bool	is_special_char(char _char)
{
	if (ft_strchr(ESPECIAL_CHARS, _char))
		return (TRUE);
	return (FALSE);
}
