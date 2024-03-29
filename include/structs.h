/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 23:50:13 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIDTH 640
# define HEIGHT 480

# include <cub3D.h>

/******************************************************************************/
/*									PARSER									  */
/******************************************************************************/

typedef struct s_parser
{
	int		f[3];
	int		c[3];
	char	*coordinates[4];
	int		coordinates_save[4];
	int		**texture;
	int		size_parser;

}	t_parse;

/******************************************************************************/
/*									MAP									  */
/******************************************************************************/

typedef struct s_map
{
	char	*file_name;
	char	**full_map;
	char	**mini_map;
	int		chars[4];
	int		size_y;
	int		size_x;
	int		fd;

	double	player[2];
	double	speed;
	double	rot_speed;
	double	dir[2];
	double	plane[2];
	int		size_parser;
	int		**texture;
	int		f;
	int		c;

}	t_map;

/******************************************************************************/
/*									IMG										  */
/******************************************************************************/

typedef struct s_img
{
	void	*img;
	int		*addr;

	int		width;
	int		height;
	int		bits_per_pixel;
	int		length;
	int		endian;

}	t_img;

/******************************************************************************/
/*									TEXTURE									  */
/******************************************************************************/

typedef struct s_tex
{
	int		x;
	int		y;
	int		num;
	int		flag;
	int		**texture;
	int		buf[HEIGHT][WIDTH];
	double	pos;
	double	wall;
	double	step;
}	t_tex;

/******************************************************************************/
/*									control									  */
/******************************************************************************/

typedef struct s_data
{
	void	*mlx;
	void	*win;

	t_tex	t;
	t_map	map;
	t_img	img;
	t_parse	parser;

}	t_data;

/******************************************************************************/
/*									AUX_POSITINOS							  */
/******************************************************************************/

typedef enum s_positions
{
	NO,
	SO,
	WE,
	EA,
}	t_directions;

/******************************************************************************/
/*									RAYCAST									  */
/******************************************************************************/

typedef struct s_raycast
{
	int		map[2];
	int		step[2];
	double	dir[2];
	double	plane[2];
	double	ray_dir[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	perp_wall;
	double	cam_x;
	int		l_height;
	int		d_start;
	int		d_end;
	int		side;
}	t_raycast;

#endif
