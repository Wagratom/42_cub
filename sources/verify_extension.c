/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:30:29 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/03 22:59:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_bool	verify_extension(char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.');
	if (ft_str_eq(extension, ".cub"))
		return (TRUE);
	//printf("Invalid Extension\n");
	return (FALSE);
}
