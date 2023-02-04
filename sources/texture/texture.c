#include <cub3D.h>
#include <texture.h>

void	texture(t_data *data, t_raycast *r, int j)
{
	int		i;
	int		color;
	t_tex	*t;

	t = &data->t;
	if (r->side == 0)
		t->wall = player_p_y(data) + r->perpWallDist * r->dir[P_Y];
	else
		t->wall = player_p_x(data) + r->perpWallDist * r->dir[P_X];
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
		color = (((int *)data->texture)[TILE_SIZE * t->y + t->x]);
		if (r->side)
			color = (color >> 1) & 8355711;
		t->buf[i][j] = color;
	}
	t->flag = 1;
}

