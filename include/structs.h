/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/01 13:14:08 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef structs_H
# define structs_H

# include <cub3D.h>

typedef struct s_map
{
	char	*file_name;
	char	**map;
	int		chars[4];
	int		p_player[2];
	int		size_y;
	int		fd;

}	t_map;

typedef struct s_data
{
	t_map	map;
}	t_data;

typedef enum	s_positions
{
	P_N,
	P_S,
	P_E,
	P_W,
}			t_positions;

#endif
