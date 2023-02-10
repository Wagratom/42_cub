/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/09 12:30:51 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3D.h>
# include <texture.h>

typedef struct s_map
{
	char	*file_name;
	char	**map;
	int		chars[4];
	int		size_y;
	int		size_x;
	int		fd;

	double		player[2];
	double		speed;
	double		rot_speed;
	double		dir[2];
	double		plane[2];

}	t_map;

typedef struct s_img
{
	void	*img;
	int		*addr;

	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_img;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**texture;

	t_tex	t;
	t_map	map;
	t_img	img;

}	t_data;

typedef enum e_directions
{
	NO,
	SO,
	EA,
	WE
}	t_directions;

typedef enum s_positions
{
	P_N,
	P_S,
	P_E,
	P_W,
}			t_positions;

typedef struct s_raycast
{
	int		map[2];
	int		step[2];	//what direction to step in x or y-direction (either +1 or -1)
	double	dir[2];
	double	plane[2];
	double	rayDir[2];
	double	sideDist[2];
	double	deltaDist[2];
	double	perpWallDist;
	double	cameraX;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		side;
}t_raycast;

#endif
