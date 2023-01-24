/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/01/24 15:48:15 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	save_position_player(t_map *data, int position_x, char _char)
{
	if (!is_special_char(_char))
		return ;
	printf("saving position \n");
	printf("X = %d y = %d\n", position_x, data->size_y - 1);
	data->player[P_X] = position_x;
	data->player[P_Y] = data->size_y - 1;
}

t_bool	interactor_chars_or_die(t_map *data, char _char)
{
	int static	validator = 0;

	if (!is_special_char(_char))
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
		//printf("Error: invalid line | position %d\n", data->size_y);
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
		//die program
	}
	return (TRUE);
}
