/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:45 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 10:32:40 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	debug_print(t_bool mod_debug, char *prefix, char *msg)
{

	if (msg == NULL)
		return ;
	if (!mod_debug)
		return ;
	if (prefix)
			write(1, prefix, ft_strlen(prefix));
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
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
