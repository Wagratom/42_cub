/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:42:14 by wwalas-           #+#    #+#             */
/*   Updated: 2023/01/31 18:35:07 by wwalas-          ###   ########.fr       */
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
	if (!ft_is_int_nbr(*dst))
	{
		write(2, "Error\n", 6);
		ft_free_ptr(dst, NULL);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	cpy_int_valid(char **dst, char *numbers)
{
	char	*number;

	if (dst == NULL)
		return (FALSE);
	if (numbers == NULL || *numbers == '\0')
		return (FALSE);
	*dst =  firts_number(numbers);
	return (is_valid_or_clear(dst));
}

void	save_in_dst(int dst[], int index, char *number)
{
	dst[index] = atoi(number);
}

t_bool	is_end_number(char *str)
{
	if (*(str + 1) != '\n')
		return (FALSE);
	return (TRUE);
}

int	check_avance_str(char **numbers, char *number)
{
	*numbers += ft_strlen(number) + 1;
	if (!is_end_number(*numbers))
		return (TRUE);
	ft_free_ptr(&number, NULL);
	return (FALSE);
}

t_bool	extract_colors(int dst[], char *numbers)
{
	char	*number;
	int		index;

	index = -1;
	while (++index < 2)
	{
		if (!cpy_int_valid(&number, numbers))
			return (FALSE);
		save_in_dst(dst, index, number);
		if (!check_avance_str(&numbers, number))
			return (FALSE);
		ft_free_ptr(&number, NULL);
	}
	if (!is_end_number(numbers))
		return (FALSE);
	return (TRUE);
}


