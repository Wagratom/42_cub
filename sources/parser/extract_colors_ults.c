/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors_ults.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/06 17:51:35 by wwalas-          ###   ########.fr       */
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
		msg_and_error("Error: parser: ", "number not integer ");
		msg_and_error(NULL, dst);
		free(dst);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	get_int_valid(char **dst, char *data_line)
{
	debug_printc(has_flag(), "Data line: ", data_line);
	if (data_line == NULL || *data_line == '\0')
		return (msg_and_error("Error: parser: ", "Data_line arrived void"));
	if (dst == NULL)
		return (msg_and_error("Error: parser: ", "Dst is pointer NULL"));
	*dst = firts_number(data_line);
	debug_printc(has_flag(), "Write in dst: ", *dst);
	return (is_valid_or_clear(*dst));
}

void	avance_is_check_end(char **data_line, char *number)
{
	*data_line += ft_strlen(number);
	if (*(*data_line) != '\0')
		*data_line += 1;
	ft_free_ptr(&number, NULL);
}
