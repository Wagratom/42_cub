/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2022/12/31 10:58:13 by hectfern         ###   ########.fr       */
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


typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_player
{
	double	speed;
	double	rot_speed;
	t_pos	pos;
	t_pos	dir;
	t_pos	plane;
}	t_player;

typedef struct s_ray
{
	int		side;
	int 	color;
	int		line_end;
	int		line_start;
	int		line_height;
	t_pos	step;
	t_pos	pos;
	t_pos	side_dist;
	t_pos	direction;
	t_pos	delta_dist;
	double	camera_x;
	double	perp_wall_dist;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;

	t_map		map;
	t_img		img;
	t_ray		ray;
	t_player	player;
}	t_data;

typedef enum s_positions
{
	P_N,
	P_S,
	P_E,
	P_W,
}			t_positions;

#endif
