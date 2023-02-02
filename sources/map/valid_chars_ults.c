/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:24:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/01 22:34:20 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	proportions_map(t_map *data, int size_x)
{
	if (size_x > data->size_x)
		data->size_x = size_x;
}

char	*get_line(t_map *data, char **line)
{
	// printf("dei free na linha %s\n\n", *line);
	free(*line);
	*line = get_next_line(data->fd);
	// printf("peguei a linha = %s", *line);
	data->size_y += 1;
	proportions_map(data, ft_strlen(*line));
	return (*line);
}

t_bool	valid_char_or_die(char _char)
{
	if (ft_strchr(VALID_CHARS, _char))
		return (TRUE);
	write(2, "Error: Invalid line\n", 20);
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
