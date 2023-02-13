/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 13:27:18 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	save_position_player(t_map *data, int position_x, char _char)
{
	if (!is_special_char(_char))
		return (msg_and_error("Error: position_p: ", "Non-special character"));
	data->player[P_X] = position_x;
	data->player[P_Y] = data->size_y;
	write_info_save(data->player[P_X], data->player[P_Y], _char);
	return (TRUE);
}

t_bool	interactor_chars_status(char _char)
{
	static int	validator = 0;

	if (!is_special_char(_char))
		return (msg_and_error("Error: interactor: ", "Non-special character"));
	if (validator > 0)
		return (msg_and_error("Error: ", "Many characters of positions"));
	validator++;
	return (TRUE);
}

/******************************************************************************/
/*									INIT									  */
/******************************************************************************/

t_bool	valid_chars_or_die(t_map *data)
{
	char	*line;

	line = ft_strdup("");
	while (get_line(data, &line))
	{
		if (valid_chars_line(data, line))
			continue ;
		wrong_write_line((data->size_y + data->size_parser + 1), line);
		free(line);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	valid_chars_line(t_map *data, char *line)
{
	int	letter;

	letter = -1;
	while (line[++letter])
	{
		if (!valid_char_or_die(line[letter]))
			return (FALSE);
		if (!is_special_char(line[letter]))
			continue ;
		if (!interactor_chars_status(line[letter]))
			return (FALSE);
		if (!save_position_player(data, letter, line[letter]))
			return (FALSE);
		if (!set_direction_player(data, line[letter]))
			return (FALSE);
	}
	return (TRUE);
}
