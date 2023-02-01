/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 10:39:49 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*get_valid_end_number(char *str)
{
	char	*is_end;

	is_end = ft_strchr(str, ',');
	if (is_end != NULL)
		return (is_end);
	return (ft_strchr(str, '\n'));
}

char	*firts_number(char *str)
{
	char	*comma;
	int		len_number;

	if (str == NULL || *str == '\0')
		return (NULL);
	comma = get_valid_end_number(str);
	len_number = comma - str;
	return (ft_substr(str, 0, len_number));
}

t_bool	is_valid_or_clear(char **dst)
{
	if (dst == NULL || *dst == NULL)
		return (FALSE);
	if (!ft_is_int_nbr(*dst))
	{
		write(2, "Errorrrr\n", 8);
		ft_free_ptr(dst, NULL);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	cpy_int_valid(char **dst, char *numbers)
{
	char	*number;

	debug_print(has_flag(), "Numeros: ", numbers);
	if (dst == NULL)
		return (FALSE);
	if (numbers == NULL || *numbers == '\0')
		return (FALSE);
	*dst =  firts_number(numbers);
	debug_print(has_flag(), "dst: ", *dst);
	return (is_valid_or_clear(dst));
}

void	save_in_dst(int dst[], int index, char *number)
{
	dst[index] = atoi(number);
}

int	avance_is_check_end(char **data, char *number)
{
	*data += ft_strlen(number) + 1;
	ft_free_ptr(&number, NULL);
}
t_bool	extract_colors(int dst[], char *data_line)
{
	char	*number;
	int		counter;

	counter = -1;
	while (++counter <= 2 && *data_line != '\0')
	{
		if (!cpy_int_valid(&number, data_line))
			return (FALSE);
		save_in_dst(dst, counter, number);
		avance_is_check_end(&data_line, number);
		printf("s = %s\n", data_line);
	}
	printf("s = %s\n", data_line);
	if (*data_line != '\0')
		return (FALSE);
	return (TRUE);
}


