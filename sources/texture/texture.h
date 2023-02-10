#ifndef TEXTURE_H
# define TEXTURE_H

#define WIDTH 640
#define HEIGHT 480
#define TILE_SIZE 64

typedef struct	s_tex
{
	int	x;
	int	y;
	int	num;
	int	flag;
	int	**texture;
	int	buf[HEIGHT][WIDTH];

	double	pos;
	double	wall;
	double	step;
} t_tex;

#endif