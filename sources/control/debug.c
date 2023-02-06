/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:45 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/05 16:10:02 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	write_msg_error(char *prefix, char *msg)
{
	if (prefix)
		write(2, prefix, ft_strlen(prefix));
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (FALSE);
}

t_bool	debug_printc(t_bool mod_debug, char *prefix, char *msg)
{
	if (!mod_debug)
		return (FALSE);
	if (prefix)
		write(1, prefix, ft_strlen(prefix));
	if (msg)
		write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	write(1, W, ft_strlen(W));
	return (FALSE);
}

t_bool	debug_printi(t_bool mod_debug, char *prefix, int number)
{
	char	*tmp;

	if (!mod_debug)
		return (FALSE);
	if (prefix)
		write(1, prefix, ft_strlen(prefix));
	tmp = ft_itoa(number);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	free(tmp);
	return (FALSE);
}
