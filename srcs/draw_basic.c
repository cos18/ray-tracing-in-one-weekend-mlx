/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:09:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/03 16:18:48 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		draw_gradaition(t_img_data *data)
{
	int		trgb;
	t_vec	*color;
	double	x;
	double	y;

	ft_printf("Start drawing!\n");
	y = -1;
	while ((++y) < data->height)
	{
		x = -1;
		while ((++x) < data->width)
		{
			color = vec_create(x / data->width * 256.0, y / data->height * 256.0, 64);
			trgb = create_trgb(0, color);
			data->img[(int)x][(int)y] = trgb;
			free(color);
		}
	}
	ft_printf("Done!\n");
}

void		draw_vertical_line(t_img_data *data, int x)
{
	int		trgb;
	t_vec	*color;
	int		y;

	ft_printf("Start drawing!\n");
	y = -1;
	while ((++y) < data->height)
	{
		color = vec_create(255, 255, 255);
		trgb = create_trgb(0, color);
		data->img[x][y] = trgb;
		free(color);
	}
	ft_printf("Done!\n");
}

void		draw_horizontal_line(t_img_data *data, int y)
{
	int		trgb;
	t_vec	*color;
	int		x;

	ft_printf("Start drawing!\n");
	x = -1;
	while ((++x) < data->height)
	{
		color = vec_create(255, 255, 255);
		trgb = create_trgb(0, color);
		data->img[x][y] = trgb;
		free(color);
	}
	ft_printf("Done!\n");
}
