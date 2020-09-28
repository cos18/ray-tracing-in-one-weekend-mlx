/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:12:06 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 11:39:39 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "minirt.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			draw_circle(t_data *data, int cx, int cy, int r, int color)
{
	int	x;
	int	y;

	x = cx - r - 1;
	while (++x <= cx + r)
	{
		y = cy - r - 1;
		while (++y <= cy + r)
		{
			if (pow(x - cx, 2) + pow(y - cy, 2) <= pow(r, 2))
				my_mlx_pixel_put(data, x, y, color);
		}
	}
}

int				key_handle(int keycode, t_vars *vars)
{
	
	ft_printf("keycode : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int				main(void)
{
	t_vars	vars;
	t_data	*img;
	int		x;
	int		y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "miniRT");
	img = (t_data *)malloc(sizeof(t_data));
	img->img = mlx_new_image(vars.mlx, 1000, 1000);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
					&(img->line_length), &(img->endian));
	draw_circle(img, 300, 300, 150, 0x55FFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_string_put(vars.mlx, vars.win, 700, 700, 0x00FFFF00, "Hello!");
	mlx_hook(vars.win, 2, 1L<<0, key_handle, &vars);
	mlx_get_screen_size(vars.mlx, &x, &y);
	ft_printf("size : %d %d\n", x, y);
	mlx_loop(vars.mlx);
	free(img);
}
