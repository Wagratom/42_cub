/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 16:29:38 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_valid_end_number(char *data_line)
{
	char	*end;

	end = ft_strchr(data_line, ',');
	if (end != NULL)
		return (end);
	end = ft_strchr(data_line, '\n');
	if (end != NULL)
		return (end);
	return (ft_strchr(data_line, '\0'));
}

char	*firts_number(char *data_line)
{
	char	*end_number;
	int		len_number;

	if (data_line == NULL || *data_line == '\0')
		return (NULL);
	end_number = get_valid_end_number(data_line);
	if (end_number == NULL)
		return (NULL);
	len_number = end_number - data_line;
	return (ft_substr(data_line, 0, len_number));
}

t_bool	is_valid_or_clear(char *dst)
{
	if (dst == NULL)
		return (FALSE);
	if (!ft_is_int_nbr(dst))
	{
		debug_printC(has_flag(), "Error number not integer: ", dst);
		write(2, "Error\n", 6);
		free(dst);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	get_int_valid(char **dst, char *data_line)
{
	char	*number;

	if (data_line == NULL || *data_line == '\0')
		return (FALSE);
	if (dst == NULL)
		return (FALSE);
	debug_printC(has_flag(), "Data line: ", data_line);
	*dst =  firts_number(data_line);
	debug_printC(has_flag(), "Write in dst: ", *dst);
	return (is_valid_or_clear(*dst));
}

void	save_in_dst(int dst[], int index, char *number)
{
	dst[index] = atoi(number);
}

int	avance_is_check_end(char **data_line, char *number)
{
	*data_line += ft_strlen(number);
	if (*(*data_line) != '\0')
		*data_line += 1;
	ft_free_ptr(&number, NULL);
}

int	extract_rgb(int dst[], char *data_line)
{
	char	*number;
	int		counter;

	counter = -1;
	while (++counter <= 2)
	{
		if (!get_int_valid(&number, data_line))
			return (-1);
		save_in_dst(dst, counter, number);
		avance_is_check_end(&data_line, number);
	}
	if (*data_line == '\0')
		return (TRUE);
	debug_printC(has_flag(), NULL, "Error: Past numbers in very large date");
	debug_printC(has_flag(), " left over: ", data_line);
	return (-1);
}

int	extract_colors_status(int dst[], char *data_line)
{
	if (dst == NULL)
		return (-1);
	if (data_line == NULL)
		return (-1);
	return (extract_rgb(dst, data_line));
}
