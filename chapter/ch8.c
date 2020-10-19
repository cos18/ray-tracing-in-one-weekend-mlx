/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch8.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:23:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/18 21:20:04 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	show_normal_sphere_anti_dif(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_camera	*cam;
	t_sphere	*s;
	t_list		*hitlst;

	aspect_ratio = 16.0 / 9.0;
	img = create_img_data(400, (int)(400 / aspect_ratio));
	cam = camera_new(aspect_ratio);
	cam->data = img;
	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, 0, -1), 0.5);
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	s = init_sphere(vec_create(0, -100.5, -1), 100);
	hitlst_add(hitlst, (void *)s, OBJ_SPHERE);
	ft_printf("Drawing start\n");
	draw_hittable_diffuse_anti(cam, hitlst);
	ft_printf("Finish Drawing\n");
	if (is_save)
		save_bmp(img, "ch8.rt");
	else
		mlx_show(img, "Diffuse");
	free_hitlst(hitlst);
	free_camera(cam);
	free_img_data(img);
}
