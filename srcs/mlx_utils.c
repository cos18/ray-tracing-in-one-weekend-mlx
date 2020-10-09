/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:13:02 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/08 20:15:08 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			mlx_draw_by_img_data(t_mlx_data *mlx_data, t_img_data *img_data)
{
	int			width;
	int			height;
	char		*dst;
	int			next;

	width = -1;
	while ((++width) < img_data->width)
	{
		height = -1;
		while ((++height) < img_data->height)
		{
			next = (img_data->height - height - 1) * mlx_data->line_length;
			next += width * (mlx_data->bits_per_pixel / 8);
			dst = mlx_data->addr + next;
			*(unsigned int*)dst = img_data->img[width][height];
		}
	}
}

int				exit_program(void)
{
	exit(0);
	return (0);
}

int				mlx_key_handle(int keycode)
{
// ft_printf("keycode : %d\n", keycode);
	if (keycode == 53)
		return (exit_program());
	return (0);
}

void			mlx_show(t_img_data *data, char *title)
{
	t_vars		vars;
	t_mlx_data	*img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width, data->height, title);
	img = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	img->img = mlx_new_image(vars.mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	mlx_draw_by_img_data(img, data);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_destroy_image(vars.mlx, img->img);
	mlx_hook(vars.win, 2, 1L << 0, mlx_key_handle, 0);
	mlx_hook(vars.win, 17, 1L << 17, exit_program, 0);
	mlx_loop(vars.mlx);
	free(img);
	ft_printf("test\n");
}
