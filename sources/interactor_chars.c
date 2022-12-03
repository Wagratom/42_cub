/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactor_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 09:36:40 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_bool	is_valid_char(char _char)
{
	if (_char == '0' || _char == '1' || _char == '\n')
		return (FALSE);
	return (TRUE);
}

void	save_position_player(t_data *data, int position_x, char _char)
{
	if (!is_valid_char(_char))
		return ;
	data->map.p_player[P_X] = position_x;
	data->map.p_player[P_Y] = data->map.size_y;
}

t_bool	interactor_chars(t_data *data, char _char, int position_x)
{
	data->map.chars[P_W] += (_char == 'W');
	data->map.chars[P_S] += (_char == 'S');
	data->map.chars[P_N] += (_char == 'N');
	data->map.chars[P_E] += (_char == 'E');
}

t_bool	interactor_chars_or_die(t_data *data, char _char, int position_x)
{
	int static	validator = 0;

	if (!is_valid_char(_char))
		return (FALSE);
	if (validator > 0)
		return (FALSE);
		//die_program
	interactor_chars(data, _char, position_x);
	save_position_player(data, position_x, _char);
	validator++;
	return (TRUE);
}
