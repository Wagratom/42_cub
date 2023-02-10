#include <cub3D.h>
#include <texture.h>


static int	get_color(t_data *data, t_raycast *r, int x, int y)
{
	if (r->side == 0 && r->rayDir[P_X] > 0)
		return(data->texture[NO][TILE_SIZE * y + x]);
	else if (r->side == 0 && r->rayDir[P_X] < 0)
		return(data->texture[SO][TILE_SIZE * y + x]);
	else if (r->side == 1 && r->rayDir[P_Y] > 0)
		return(data->texture[WE][TILE_SIZE * y + x]);
	else
		return(data->texture[EA][TILE_SIZE * y + x]);
}

void	texture(t_data *data, t_raycast *r, int j)
{
	int		i;
	t_tex	*t;

	t = &data->t;
	if (r->side == 0)
		t->wall = player_p_y(data) + r->perpWallDist * r->rayDir[P_Y];
	else
		t->wall = player_p_x(data) + r->perpWallDist * r->rayDir[P_X];
	if (r->dir[P_X] < 0 || r->dir[P_Y] < 0)
		t->wall = TILE_SIZE - t->wall;
	t->wall -= floor(t->wall);
	t->x = (int)(t->wall * (double)TILE_SIZE);
	if((r->side == 0 && r->dir[P_X] > 0) || (r->side == 1 && r->dir[P_Y] < 0))
		t->x = TILE_SIZE - t->x - 1;
	t->step = 1.0 * TILE_SIZE / r->lineHeight;
	t->pos = (r->drawStart - HEIGHT / 2 + r->lineHeight / 2) * t->step;
	i = r->drawStart - 1;
	while (++i < r->drawEnd)
	{
		t->y = (int)t->pos & (TILE_SIZE - 1);
		t->pos += t->step;
		t->buf[i][j] = get_color(data, r, t->x, t->y);
	}
	t->flag = 1;
}

