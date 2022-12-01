/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/01 11:04:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <libft.h>
#include <mlx.h>
#include <structs.h>

#include <stdio.h>

#define VALID_CHARS "01NSEW\n"
t_bool		verify_extension(char *file_name);
t_bool		open_file(t_data *data, char *file_name);
t_bool		valid_chars_line(t_data *data, char *line);

#endif
