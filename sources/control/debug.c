/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:45 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/04 11:32:52 by wwalas-          ###   ########.fr       */
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

t_bool	debug_printC(t_bool mod_debug, char *prefix, char *msg)
{
	if (!mod_debug)
		return (FALSE);
	if (prefix)
		write(1, prefix, ft_strlen(prefix));
	if (msg)
		write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	return (FALSE);
}

t_bool	debug_printI(t_bool mod_debug, char *prefix, int number)
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
