/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:09:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/08 14:46:43 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		draw_gradaition(t_img_data *data)
{
	int		trgb;
	t_vec	*color;
	double	x;
	double	y;

	y = -1;
	while ((++y) < data->height)
	{
		x = -1;
		while ((++x) < data->width)
		{
			color = vec_create(x / data->width, y / data->height, 1.0 / 4.0);
			vec_mul_const_apply(color, 256.0);
			trgb = create_trgb(0, color);
			data->img[(int)x][(int)y] = trgb;
			free(color);
		}
	}
}

void		draw_vertical_line(t_img_data *data, int x)
{
	int		trgb;
	t_vec	*color;
	int		y;

	y = -1;
	while ((++y) < data->height)
	{
		color = vec_create(255, 255, 255);
		trgb = create_trgb(0, color);
		data->img[x][y] = trgb;
		free(color);
	}
}

void		draw_horizontal_line(t_img_data *data, int y)
{
	int		trgb;
	t_vec	*color;
	int		x;

	x = -1;
	while ((++x) < data->height)
	{
		color = vec_create(255, 255, 255);
		trgb = create_trgb(0, color);
		data->img[x][y] = trgb;
		free(color);
	}
}
