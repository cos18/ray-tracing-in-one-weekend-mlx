/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch13.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:23:30 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 08:28:05 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec	*get_random_center(int a, int b)
{
	t_vec	*result;
	t_vec 	*tmp;
	double	length;

	result = vec_create(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
	tmp = vec_sub_apply(vec_create(4, 0.2, 0), result);
	length = vec_length(tmp);
	free(tmp);
	if (length <= 0.9)
	{
		free(result);
		return get_random_center(a, b);
	}
	return (result);
}

t_list	*random_scene()
{
	t_sphere	*s;
	t_list		*hitlst;
	t_material	*mat;
	t_vec		*center;
	double		choose_mat;
	
	hitlst = hitlst_new();
	s = init_sphere(vec_create(0, -1000, 0), 1000);
	mat = mat_lambertian_new(vec_create(0.5, 0.5, 0.5));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			choose_mat = random_double();
			center = get_random_center(a, b);
			if (choose_mat < 0.8)
				mat = mat_lambertian_new(vec_random_range(0, 1));
			else
				mat = mat_metal_new(vec_random_range(0.5, 1), random_double_range(0, 0.5));
			s = init_sphere(center, 0.2);
			hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
			free_material(mat);
		}
	}
	s = init_sphere(vec_create(0, 1, 0), 1.0);
	mat = mat_lambertian_new(vec_create(0.4, 0.2, 0.1));
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	s = init_sphere(vec_create(-4, 1, 0), 1.0);
	mat = mat_metal_new(vec_create(0.7, 0.6, 0.5), 0);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	s = init_sphere(vec_create(4, 1, 0), 1.0);
	mat = mat_metal_new(vec_create(0.7, 0.6, 0.5), 0);
	hitlst_mat_add(hitlst, (void *)s, OBJ_SPHERE, mat);
	free_material(mat);
	return (hitlst);
}

void	show_final(int is_save)
{
	double		aspect_ratio;
	t_img_data	*img;
	t_camera	*cam;
	t_list		*hitlst;

	ft_printf("WARNING! This example takes about 2~3 hours to render.\n");
	aspect_ratio = 3.0 / 2.0;
	img = create_img_data(1200, (int)(1200 / aspect_ratio));
	cam = camera_locate_new(vec_create(13, 2, 3), vec_create(-13, -2, -3), aspect_ratio, get_radian(20));
	cam->data = img;
	hitlst = random_scene();
	ft_printf("Drawing start\n");
	draw_hittable_material(cam, hitlst);
	ft_printf("Finish Drawing\n");
	if (is_save)
		save_bmp(img, "ch13.rt");
	else
		mlx_show(img, "Final");
	free_hitlst(hitlst);
	free_camera(cam);
	free_img_data(img);
}
