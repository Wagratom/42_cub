/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:45 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/27 14:42:46 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	debug_print(t_bool mod_debug, char *msg)
{
	if (mod_debug)
		write(1, msg, ft_strlen(msg));
}

t_bool	*flag(void)
{
	static t_bool	store;

	return (&store);
}

void	set_flag(t_bool _flag)
{
	*flag() = _flag;
}

t_bool	has_flag(void)
{
	return (*flag());
}
