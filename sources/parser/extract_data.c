/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 15:55:53 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*data_in_line(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);
	return ((ft_strchr(str, ' ') + 1));
}

int	open_file_parser(int *dst, char *path_file)
{
	*dst =  open(path_file, O_RDONLY);
	if (*dst >= 0)
		return (0);
	perror("");
	return (-1);
}

int collor_rgb(char *line)
{
	if (compare_strings(first_word(line), "F"))
		return (1);
	else if (compare_strings(first_word(line), "C"))
		return (2);
	return (0);
}

int	fill_collor(int collor, char *numbers, t_parser *data)
{
	if (collor == 0)
		return (0);
	if (collor == 1)
		extract_colors(data->f, numbers);
	if (collor == 2)
		extract_colors(data->c, numbers);
	return (1);
}

t_bool	extract_data_parser(t_parser *data, char **full_map)
{
	int		status;
	int		index;

	index = -1;
	while (full_map[++index])
	{
		status = open_texture(coordinates(full_map[index]), data_in_line(full_map[index]), data);
		if (status == -1)
			return (FALSE);
		if (status == 1)
			continue;
		status = fill_collor(collor_rgb(full_map[index]), data_in_line(full_map[index]), data);
		if (status == -1)
			return (FALSE);
		if (status == 1)
			continue;
		break ;
	}
}
