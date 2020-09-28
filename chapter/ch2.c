/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:24:03 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 14:28:36 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_gradation()
{
	t_vars	vars;
	t_data	*img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 256, 256, "miniRT");
	img = (t_data *)malloc(sizeof(t_data));
	img->img = mlx_new_image(vars.mlx, 256, 256);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	draw_gradaition(img, 256, 256);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, &vars);
	mlx_loop(vars.mlx);
	free(img);
}