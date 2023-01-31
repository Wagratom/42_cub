/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/30 18:31:38 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	extract_colors_f(char *str)
{
	t_bool	status;
	char	*floor;

	status = TRUE;
	floor = first_word(str);
	if (!ft_str_eq(floor, "F"))
		status = FALSE;
	free(floor);
	floor = NULL;
	return (status);
}
