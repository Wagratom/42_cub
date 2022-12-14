/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_ults.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:24:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/13 22:13:54 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_line(t_map *data, char **line)
{
	free(*line);
	*line = get_next_line(data->fd);
	data->size_y++;
	return (*line);
}

t_bool	valid_char_or_die(char letter)
{
	if (ft_strchr(VALID_CHARS, letter))
		return (TRUE);
	printf("invalid character \"%c\"", letter); // die program
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
	if (_char == '0' || _char == '1' || _char == '\n')
		return (FALSE);
	return (TRUE);
}
