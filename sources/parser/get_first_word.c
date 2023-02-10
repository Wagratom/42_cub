/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:37:33 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/01 23:29:47 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*first_word(char *str)
{
	char	*end_word;
	int		len_word;

	if (str == NULL || *str == '\0')
		return (NULL);
	end_word = ft_strchr(str, ' ');
	if (end_word == NULL)
		return (NULL);
	len_word = end_word - str;
	return (ft_substr(str, 0, len_word));
}
