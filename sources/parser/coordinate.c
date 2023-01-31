/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 13:13:48 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_data_parser(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);
	return ((ft_strchr(str, ' ') + 1));
}


t_bool	compare_strings(char *first_word, char *coordinate)
{
	t_bool	status;

	status = TRUE;
	status = ft_str_eq(first_word, coordinate);
	free(first_word);
	return (status);
}
