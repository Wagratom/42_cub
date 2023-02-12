/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:26:37 by hectfern          #+#    #+#             */
/*   Updated: 2023/02/11 23:49:16 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	get_color(t_data *data, t_raycast *r, int x, int y)
{
	if (r->side == 0 && r->ray_dir[P_X] > 0)
		return (data->map.texture[NO][TILE_SIZE * y + x]);
	else if (r->side == 0 && r->ray_dir[P_X] < 0)
		return (data->map.texture[SO][TILE_SIZE * y + x]);
	else if (r->side == 1 && r->ray_dir[P_Y] > 0)
		return (data->map.texture[WE][TILE_SIZE * y + x]);
	else
		return (data->map.texture[EA][TILE_SIZE * y + x]);
}

void	texture(t_data *data, t_raycast *r, int j)
{
	int		i;
	t_tex	*t;

	t = &data->t;
	if (r->side == 0)
		t->wall = player_p_y(data) + r->perp_wall * r->ray_dir[P_Y];
	else
		t->wall = player_p_x(data) + r->perp_wall * r->ray_dir[P_X];
	if (r->dir[P_X] < 0 || r->dir[P_Y] < 0)
		t->wall = TILE_SIZE - t->wall;
	t->wall -= floor(t->wall);
	t->x = (int)(t->wall * (double)TILE_SIZE);
	if ((r->side == 0 && r->dir[P_X] > 0) || (r->side == 1 && r->dir[P_Y] < 0))
		t->x = TILE_SIZE - t->x - 1;
	t->step = 1.0 * TILE_SIZE / r->l_height;
	t->pos = (r->d_start - HEIGHT / 2 + r->l_height / 2) * t->step;
	i = r->d_start - 1;
	while (++i < r->d_end)
	{
		t->y = (int)t->pos & (TILE_SIZE - 1);
		t->pos += t->step;
		t->buf[i][j] = get_color(data, r, t->x, t->y);
	}
	t->flag = 1;
}
