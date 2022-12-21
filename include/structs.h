/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/21 11:43:05 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3D.h>

typedef struct s_map
{
	char	*file_name;
	char	**map;
	int		chars[4];
	int		p_player[2];
	int		size_y;
	int		size_x;
	int		fd;

}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_img;


typedef struct s_data
{
	void	*mlx;
	void	*win;

	t_map	map;
	t_img	img;
}	t_data;

typedef enum s_positions
{
	P_N,
	P_S,
	P_E,
	P_W,
}			t_positions;

typedef struct s_raycast
{
	double	dirX[2];
	double	plane[2];
}t_raycast;

#endif
