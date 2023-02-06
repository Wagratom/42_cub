/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:45 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/05 16:09:58 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
