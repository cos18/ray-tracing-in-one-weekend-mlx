/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:09:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 16:18:12 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			draw_gradaition(t_data *data, int width, int height)
{
	int		trgb;
	t_vec	*color;
	double	x;
	double	y;

	ft_printf("Start drawing!\n");
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			color = vec_create(x / width * 256, y / height * 256, 64);
			trgb = create_trgb(0, color);
			my_mlx_pixel_put(data, x, y, trgb);
			x++;
			free(color);
		}
		y++;
	}
	ft_printf("Done!\n");
}
