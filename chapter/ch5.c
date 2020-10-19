/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:23:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/18 21:19:44 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_s_sphere(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_sky_info	*info;
	t_sphere	*s;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	info = init_sky_info(2.0 * aspect_ratio, 2.0, 1.0);
	draw_sky(img, info);
	s = init_sphere(vec_create(0, 0, -1), 0.5);
	draw_s_sphere(img, info, s);
	if (is_save)
		save_bmp(img, "ch5.rt");
	else
		mlx_show(img, "Simple Sphere at Sky");
	free_sphere(s);
	free(info);
	free_img_data(img);
}
