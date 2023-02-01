/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 13:34:27 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_valid_end_number(char *data_line)
{
	char	*is_end;

	is_end = ft_strchr(data_line, ',');
	if (is_end != NULL)
		return (is_end);
	return (ft_strchr(data_line, '\n'));
}

char	*firts_number(char *data_line)
{
	char	*comma;
	int		len_number;

	if (data_line == NULL || *data_line == '\0')
		return (NULL);
	comma = get_valid_end_number(data_line);
	len_number = comma - data_line;
	return (ft_substr(data_line, 0, len_number));
}

t_bool	is_valid_or_clear(char **dst)
{
	if (dst == NULL || *dst == NULL)
		return (FALSE);
	if (!ft_is_int_nbr(*dst))
	{
		debug_printC(has_flag(), "Error number not integer: ", *dst);
		write(2, "Error\n", 6);
		ft_free_ptr(dst, NULL);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	cpy_int_valid(char **dst, char *data_line)
{
	char	*number;

	debug_printC(has_flag(), "Data line: ", data_line);
	if (dst == NULL)
		return (FALSE);
	if (data_line == NULL || *data_line == '\0')
		return (FALSE);
	*dst =  firts_number(data_line);
	debug_printC(has_flag(), "Write in dst: ", *dst);
	return (is_valid_or_clear(dst));
}

void	save_in_dst(int dst[], int index, char *number)
{
	dst[index] = atoi(number);
}

int	avance_is_check_end(char **data_line, char *number)
{
	*data_line += ft_strlen(number) + 1;
	ft_free_ptr(&number, NULL);
}

t_bool	extract_colors(int dst[], char *data_line)
{
	char	*number;
	int		counter;

	counter = -1;
	while (++counter <= 2)
	{
		if (!cpy_int_valid(&number, data_line))
			return (FALSE);
		save_in_dst(dst, counter, number);
		avance_is_check_end(&data_line, number);
	}
	if (*data_line == '\0')
		return (TRUE);
	debug_printC(has_flag(), NULL, "Error: Past numbers in very large date");
	debug_printC(has_flag(), " left over: ", data_line);
	return (FALSE);
}


