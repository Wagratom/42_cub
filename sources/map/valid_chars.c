/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/04 15:57:18 by wwallas-         ###   ########.fr       */
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
		return (-1);
	if (validator > 0)
	{
		printf("Error: many characters of positions\n"); // die program
		return (FALSE);
	}
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
		//printf("Error: invalid line | position %d\n", data->size_y);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	valid_chars_line(t_map *data, char *line)
{
	int	letter;
	int	status;

	letter = -1;
	while (line[++letter])
	{
		status = valid_char_or_die(line[letter]); // esse status e somente para passar nos test pode remover na hr de entregar
		if (status == FALSE)
			return (FALSE);
		status = interactor_chars_or_die(data, line[letter]);
		if (status == FALSE)
			return (FALSE);
		else if (status == TRUE)
			save_position_player(data, letter, line[letter]);
		//die program
	}
	return (TRUE);
}
