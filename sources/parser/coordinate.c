/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/30 16:35:44 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_coordinate(char *str)
{
	char	*end_word;
	int		len_word;

	end_word = ft_strchr(str, ' ');
	len_word = end_word - str;
	return (ft_substr(str, 0, len_word));
}

t_bool	is_texture_north(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = get_coordinate(str);
	if (!ft_str_eq(coordinate, "NO"))
		status = FALSE;
	free(coordinate);
	coordinate = NULL;
	return (status);
}

t_bool	is_texture_south(char *str)
{
	char	*coordinate;
	t_bool	status;


	status = TRUE;
	coordinate = get_coordinate(str);
	if (!ft_str_eq(coordinate, "SO"))
		status = FALSE ;
	free(coordinate);
	return (status);
}

t_bool	is_texture_west(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = get_coordinate(str);
	if (!ft_str_eq(coordinate, "WE"))
		status = FALSE ;
	free(coordinate);
	return (status);
}

t_bool	is_texture_east(char *str)
{
	char	*coordinate;
	t_bool	status;

	status = TRUE;
	coordinate = get_coordinate(str);
	if (!ft_str_eq(coordinate, "EA"))
		status = FALSE ;
	free(coordinate);
	return (status);
}
