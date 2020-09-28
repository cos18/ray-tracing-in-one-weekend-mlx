/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:09:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 14:26:56 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			draw_gradaition(t_data *data, int width, int height)
{
	int		trgb;
	double	x;
	double	y;

	ft_printf("Start drawing!\n");
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			trgb = create_trgb(0, x / width * 256, y / height * 256, 64);
			my_mlx_pixel_put(data, x, y, trgb);
			x++;
		}
		y++;
	}
	ft_printf("Done!\n");
}
