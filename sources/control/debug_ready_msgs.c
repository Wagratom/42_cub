/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ready_msgs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:10:00 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 17:10:56 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	wrong_write_line(int position, char *line)
{
	debug_printc(has_flag(), "line: ", line);
	debug_printi(has_flag(), "Position line: ", position);
}

void	write_info_save(int position_x, int position_y, char _char)
{
	char	*aux;
	char	*aux2;

	if (!has_flag())
		return ;
	aux = ft_strdup("X(");
	aux2 = ft_itoa(position_x);
	aux = ft_robustjoin(&aux, &aux2);
	aux2 = ft_strdup(") Y(");
	aux = ft_robustjoin(&aux, &aux2);
	aux2 = ft_itoa(position_y);
	aux = ft_robustjoin(&aux, &aux2);
	aux2 = ft_strdup(") char(");
	aux = ft_robustjoin(&aux, &aux2);
	write(1, "Player position: ", 17);
	write(1, aux, ft_strlen(aux));
	write(1, &_char, 1);
	write(1, ")", 1);
	write(1, "\n", 1);
	free(aux);
}
