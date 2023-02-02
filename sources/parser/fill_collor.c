/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_collor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 22:06:30 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int collor_rgb(char *line)
{
	debug_printC(has_flag(), "\tGet line collor: ", line);
	if (compare_strings(first_word(line), "F"))
		return (1);
	else if (compare_strings(first_word(line), "C"))
		return (2);
	return (0);
}

int	fill_collor(int collor, char *numbers, t_parse *data)
{
	int	status;

	status = 0;
	debug_printI(has_flag(), "Collor: ", collor);
	if (collor == 1)
		status = extract_colors_status(data->f, numbers);
	if (collor == 2)
		status = extract_colors_status(data->c, numbers);
	free(numbers);
	return (1);
}
