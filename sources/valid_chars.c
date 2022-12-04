/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 22:43:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	save_position_player(t_map *data, int position_x, char _char)
{
	if (!is_valid_char(_char))
		return ;
	data->p_player[P_X] = position_x;
	data->p_player[P_Y] = data->size_y;
}

t_bool	interactor_chars_or_die(t_map *data, char _char)
{
	int static	validator = 0;

	if (!is_valid_char(_char))
		return (FALSE);
	if (validator > 0)
		return (FALSE);
		//die_program
	interactor_chars(data, _char);
	validator++;
	return (TRUE);
}
/*******************************************************************************/
/*									INIT									   */
/*******************************************************************************/

t_bool	valid_chars_or_die(t_map *data)
{
	char	*line;

	line = ft_strdup("");
	while (get_line(data, &line))
	{
		if (valid_chars_line(data, line))
			continue ;
		printf("Error: invalid line\n");
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
		if (!valid_char_or_die(line[letter])) // if somente para passar nos test pode remover na hr de entregar
			return (FALSE);
		if (interactor_chars_or_die(data, line[letter]))
			save_position_player(data, letter, line[letter]);

		//die program
	}
	return (TRUE);
}
