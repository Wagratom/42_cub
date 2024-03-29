/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgbs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectfern <hectfern@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:58:36 by wwalas-           #+#    #+#             */
/*   Updated: 2023/02/12 21:31:37 by hectfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	create_rgbf(t_data *data)
{
	int	f[3];

	f[0] = data->parser.f[0];
	f[1] = data->parser.f[1];
	f[2] = data->parser.f[2];
	data->map.f = create_trgb(1, f[0], f[1], f[2]);
}

static void	create_rgbc(t_data *data)
{
	int	c[3];

	c[0] = data->parser.c[0];
	c[1] = data->parser.c[1];
	c[2] = data->parser.c[2];
	data->map.c = create_trgb(1, c[0], c[1], c[2]);
}

t_bool	create_rgbs(t_data *data)
{
	if (data->parser.f[0] == -1 || data->parser.c[0] == -1)
	{
		msg_and_error("Error: parser: ", "Missing collor");
		return (FALSE);
	}
	create_rgbf(data);
	create_rgbc(data);
	return (TRUE);
}
