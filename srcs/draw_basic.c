/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:09:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 13:06:35 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		draw_gradaition(t_img_data *data)
{
	int		rgb;
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
			rgb = get_color_val(color);
			data->img[(int)x][(int)y] = rgb;
			free(color);
		}
	}
}

void		draw_vertical_line(t_img_data *data, int x)
{
	int		rgb;
	t_vec	*color;
	int		y;

	y = -1;
	while ((++y) < data->height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data->img[x][y] = rgb;
		free(color);
	}
}

void		draw_horizontal_line(t_img_data *data, int y)
{
	int		rgb;
	t_vec	*color;
	int		x;

	x = -1;
	while ((++x) < data->height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data->img[x][y] = rgb;
		free(color);
	}
}
