/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 13:02:20 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*firts_number(char *str)
{
	char	*comma;
	int		len_number;

	comma = ft_strchr(str, ',');
	len_number = comma - str;
	return (ft_substr(str, 0, len_number));
}

t_bool	cpy_int_valid(char **dst, char *data)
{
	char	*number;

	*dst =  firts_number(data);
	if (dst != NULL && ft_is_int_nbr(*dst))
		return (TRUE);
	write(2, "Error\n", 6);
	ft_free_ptr(dst, NULL);
	return (FALSE);
}

void	save_in_dst(int dst[], int index, char *number_str)
{
	dst[index] = atoi(number_str);
}

t_bool	save_collors(int dst[], char *str)
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

