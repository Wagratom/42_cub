/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:30:29 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/06 16:46:00 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	open_file_status(int *dst, char *path_file)
{
	*dst = open(path_file, O_RDONLY);
	if (*dst >= 0)
		return (TRUE);
	perror("");
	return (FALSE);
}
