/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 14:41:19 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	save_position_player(t_map *data, int position_x, char _char)
{
	if (!is_special_char(_char))
		return ;
	data->player[P_X] = position_x;
	data->player[P_Y] = data->size_y;
	if (has_flag())
		write_info_save(data->player[P_X], data->player[P_Y], _char);
}

t_bool	interactor_chars_or_die(t_map *data, char _char)
{
	int static	validator = 0;

	if (!is_special_char(_char))
		return (FALSE);
	if (validator > 0)
		return (msg_and_error("Error: ", "Many characters of positions\n"));
	interactor_chars(data, _char);
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
		wrong_write_line((data->size_y + data->size_d_map), line);
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
		if (!interactor_chars_or_die(data, line[letter]))
			return (FALSE);
		save_position_player(data, letter, line[letter]);
		set_direction_player(data, line[letter]);
	}
	return (TRUE);
}
