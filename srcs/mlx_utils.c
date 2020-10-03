/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:13:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/03 12:31:27 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
	int			width;
	int			height;
	char		*dst;

	width = -1;
	while ((++width) < img_data->width)
	{
		height = -1;
		while ((++height) < img_data->height)
		{
			dst = mlx_data->addr + (height * mlx_data->line_length + width * (mlx_data->bits_per_pixel / 8));
			*(unsigned int*)dst = img_data->img[width][height];
		}
	}
}

int				mlx_key_handle(int keycode, t_vars *vars)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void			mlx_show(t_img_data *data)
{
	t_vars		vars;
	t_mlx_data	*img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, "Gradation");
	img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, 256, 256);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	mlx_draw_by_img_data(img, data);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, img->img);
	free(img);
	ft_printf("test\n");
}
