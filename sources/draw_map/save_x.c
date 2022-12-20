/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:56:27 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/20 16:04:34 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	*value_x(void)
{
	static int	save = 0;

	return (&save);
}

void	save_value_x(int nbr)
{
	*value_x() = nbr;
}

int	get_save_x(void)
{
	return (*value_x());
}

int	get_size_y(int nbr)
{
	return (nbr + 5);
}

