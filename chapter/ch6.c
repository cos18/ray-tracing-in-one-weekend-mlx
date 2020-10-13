/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:23:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/14 05:39:21 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	show_normal_sphere(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_sky_info	*info;
	t_sphere	*s;
	t_list		*hitlst;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	info = init_sky_info(2.0 * aspect_ratio, 2.0, 1.0);
	draw_sky(img, info);
	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, 0, -1), 0.5, vec_create(255, 0, 0));
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	s = init_sphere(vec_create(0, -100.5, -1), 100, vec_create(255, 0, 0));
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	draw_hittable(img, info, hitlst);
	if (is_save)
		save_bmp(img, "ch6.rt");
	else
		mlx_show(img, "Normals-colored Sphere with Ground");
	free_hitlst(hitlst);
	free(info);
	free_img_data(img);
}
