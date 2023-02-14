/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:14:25 by hectfern          #+#    #+#             */
/*   Updated: 2023/02/13 22:32:50 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	has_player(t_data *data)
{
	if (data->map.player[0] == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	valid_map_chars(t_data *data)
{
	debug_printc(has_flag(), C, "\tValiding chars of map...");
	if (!valid_chars_or_die(&data->map))
		return (FALSE);
	if (!has_player(data))
		return (msg_and_error("Error: ", "Player not passed"));
	close(data->map.fd);
	debug_printc(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

t_bool	valid_map_exit(t_data *data)
{
	debug_printc(has_flag(), C, "\tValidating map exit...");
	return (verify_exit_status(&data->map));
}
