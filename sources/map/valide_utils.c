/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:14:25 by hectfern          #+#    #+#             */
/*   Updated: 2023/02/11 20:18:01 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	valid_map_chars(t_data *data)
{
	debug_printc(has_flag(), C, "\tValiding chars of map...");
	if (!valid_chars_or_die(&data->map))
		return (FALSE);
	close(data->map.fd);
	debug_printc(has_flag(), "Validacion: ", "Chars: Ok\n");
	return (TRUE);
}

t_bool	valid_map_exit(t_data *data)
{
	debug_printc(has_flag(), C, "\tValidating map exit...");
	return (verify_exit_status(&data->map));
}
