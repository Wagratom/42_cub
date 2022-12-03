/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 09:37:20 by wwallas-         ###   ########.fr       */
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

t_bool	valid_char_or_die(char letter)
{
	if (!ft_strchr(VALID_CHARS, letter))
		return (FALSE);
	//invalid character die
	return (TRUE);
}

t_bool	valid_chars(t_data *data, int file)
{
	char	*line;

	line == NULL;
	while (get_line(data, &line))
		valid_chars_line(data, line);
	return (TRUE);
}

t_bool	valid_chars_line(t_data *data, char *line)
{
	int	letter;

	letter = -1;
	while (line[++letter])
	{
		if (!valid_char_or_die(line[letter])) // if somente para passar nos test pode remover na hr de entregar
			return (FALSE);
		interactor_chars_or_die(data, line[letter], letter);
		//die program
	}
	return (TRUE);
}
