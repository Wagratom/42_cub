/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwalas- <wwallas-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:32:06 by wwallas-          #+#    #+#             */
/*   Updated: 2023/02/11 11:32:57 by wwalas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <cub3D.h>
# include <texture.h>

/******************************************************************************/
/*									PARSER									  */
/******************************************************************************/
typedef struct s_parser
{
	int	f[3];
	int	c[3];
	char	*coordinates[4];
	int		coordinates_save[4];
	int	**texture;
	int	size_parser;

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

	int		size_d_map;

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
	int		line_length;
	int		endian;

}	t_img;

/******************************************************************************/
/*									control									  */
/******************************************************************************/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**texture;

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
}	t_raycast;

#endif
