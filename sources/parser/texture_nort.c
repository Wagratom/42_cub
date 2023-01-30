/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_nort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/30 15:02:37 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	is_texture_north(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = ft_substr(str, 0, 2);
	if (!ft_str_eq(str, "NO"))
		status = FALSE ;
	free(coordinate);
	return (status);
}

t_bool	is_texture_south(char *str)
{
	char	*coordinate;
	t_bool	status;


	status = TRUE;
	coordinate = ft_substr(str, 0, 2);
	if (!ft_str_eq(str, "SO"))
		status = FALSE ;
	free(coordinate);
	return (status);
}

t_bool	is_texture_west(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = ft_substr(str, 0, 2);
	if (!ft_str_eq(str, "WE"))
		status = FALSE ;
	free(coordinate);
	return (status);
}

t_bool	is_texture_east(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = ft_substr(str, 0, 2);
	if (!ft_str_eq(str, "EA"))
		status = FALSE ;
	free(coordinate);
	return (status);
}
