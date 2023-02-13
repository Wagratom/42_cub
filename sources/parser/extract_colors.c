/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/11 09:42:33 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	save_in_dst(int dst[], int index, char *number)
{
	dst[index] = atoi(number);
}

int	extract_colors_status(int dst[], char *data_line)
{
	if (dst == NULL)
		return (INVALID_DATA);
	if (data_line == NULL)
		return (INVALID_DATA);
	return (extract_rgb(dst, data_line));
}

int	extract_rgb(int dst[], char *data_line)
{
	char	*number;
	int		counter;

	counter = -1;
	while (++counter <= 2)
	{
		if (!get_int_valid(&number, data_line))
			return (INVALID_DATA);
		save_in_dst(dst, counter, number);
		avance_is_check_end(&data_line, number);
	}
	if (*data_line == '\0')
		return (NEW_LINE);
	msg_and_error("Error: parser: ", "Past numbers in very large date");
	msg_and_error("Left over: ", data_line);
	return (INVALID_DATA);
}
