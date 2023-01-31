/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 10:07:28 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_data_parser(char *str)
{
	return ((ft_strchr(str, ' ') + 1));
}


t_bool	compare_strings(char *first_word, char *coordinate)
{
	t_bool	status;

	status = TRUE;
	if (!ft_str_eq(first_word, coordinate))
		status = FALSE ;
	free(first_word);
	return (status);
}
