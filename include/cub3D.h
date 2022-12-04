/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/04 14:16:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <structs.h>

# include <stdio.h>

# define VALID_CHARS "01NSEW\n"

# define P_Y 0
# define P_X 1

t_bool		verify_extension(char *file_name);

t_bool		open_file_or_die(t_map *data);

t_bool		valid_map(t_map *data);
t_bool		valid_chars_or_die(t_map *data);
t_bool		valid_chars_line(t_map *data, char *line);

char		*get_line(t_map *data, char **line);
t_bool		interactor_chars(t_map *data, char _char);
t_bool		is_valid_char(char _char);
t_bool		valid_char_or_die(char letter);




t_bool		interactor_chars_or_die(t_map *data, char _char);
void		alloc_map_or_die(t_map *data);
t_bool		verify_exit_or_die(t_map *data);

void		draw_map(char **map);

#endif
