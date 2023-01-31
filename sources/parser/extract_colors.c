/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 13:30:14 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*firts_number(char *str)
{
	char	*comma;
	int		len_number;

	if (str == NULL || *str == '\0')
		return (NULL);
	comma = ft_strchr(str, ',');
	len_number = comma - str;
	return (ft_substr(str, 0, len_number));
}

t_bool	is_valid_or_clear(char **dst)
{
	if (dst == NULL || *dst == NULL)
		return (FALSE);
	if (ft_is_int_nbr(*dst) == FALSE)
	{
		write(2, "Error\n", 6);
		ft_free_ptr(dst, NULL);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	cpy_int_valid(char **dst, char *data)
{
	char	*number;

	if (dst == NULL)
		return (FALSE);
	if (data == NULL || *data == '\0')
		return (FALSE);
	*dst =  firts_number(data);
	return (is_valid_or_clear(dst));
}

void	save_in_dst(int dst[], int index, char *number_str)
{
	dst[index] = atoi(number_str);
}

t_bool	extract_colors(int dst[], char *str)
{
	char	*number_str;
	int		index = 0;

	while (index < 3)
	{
		if (cpy_int_valid(&number_str, str) == FALSE)
			return (FALSE);
		save_in_dst(dst, index, number_str);
		str += ft_strlen(number_str);
		ft_free_ptr(&number_str, NULL);
	}
	return (TRUE);
}

