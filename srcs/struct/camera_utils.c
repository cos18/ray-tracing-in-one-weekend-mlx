/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:33:13 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/25 11:58:36 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			set_camera_llc(t_camera *cam, t_vec *lookat)
{
	t_vec		*tmp;

	vec_div_const_apply(cam->horizontal, 2.0);
	vec_div_const_apply(cam->vertical, 2.0);
	tmp = vec_add(cam->horizontal, cam->vertical);
	vec_add_apply(tmp, lookat);
	cam->lower_left_corner = vec_sub(cam->origin, tmp);
	free(tmp);
	vec_mul_const_apply(cam->horizontal, 2.0);
	vec_mul_const_apply(cam->vertical, 2.0);
}

t_camera		*camera_new(double aspect_ratio)
{
	t_camera	*result;
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_vec		*tmp;

	result = (t_camera *)malloc(sizeof(t_camera));
	result->aspect_ratio = aspect_ratio;
	viewport_height = 2.0;
	viewport_width = viewport_height * aspect_ratio;
	focal_length = 1.0;
	result->origin = vec_create(0, 0, 0);
	result->horizontal = vec_create(viewport_width, 0, 0);
	result->vertical = vec_create(0, viewport_height, 0);
	tmp = vec_create(0, 0, focal_length);
	set_camera_llc(result, tmp);
	free(tmp);
	return (result);
}

/*
** vfov -> radian
** lookat : camera view vector (normal vector)
*/

t_camera		*camera_locate_new(t_vec *lookfrom, t_vec *lookat,
									double aspect_ratio, double vfov)
{
	t_camera	*result;
	double		view_h;
	double		view_w;
	t_vec		*vup;

	vec_unit_apply(vec_mul_const_apply(lookat, -1.0));
	vup = vec_create(0, 1, 0);
	if (vec_is_parallel(vup, lookat))
	{
		free(vup);
		vup = vec_create(1, 0, 0);
	}
	result = (t_camera *)malloc(sizeof(t_camera));
	view_h = 2.0 * tan(vfov / 2.0);
	view_w = view_h * aspect_ratio;
	result->horizontal = vec_unit_apply(vec_cross_apply(vup, lookat));
	result->vertical = vec_mul_const_apply(
							vec_cross(lookat, result->horizontal), view_h);
	vec_mul_const_apply(result->horizontal, view_w);
	result->origin = lookfrom;
	set_camera_llc(result, lookat);
	free(lookat);
	return (result);
}

t_ray			*camera_get_ray(t_camera *cam, double u, double v)
{
	t_vec		*tmp;
	t_vec		*tmp2;

	tmp2 = vec_mul_const(cam->horizontal, u);
	tmp = vec_add(cam->lower_left_corner, tmp2);
	free(tmp2);
	tmp2 = vec_mul_const(cam->vertical, v);
	vec_add_apply(tmp, tmp2);
	free(tmp2);
	vec_sub_apply(tmp, cam->origin);
	return (ray_create(cam->origin, tmp));
}

void			free_camera(t_camera *cam)
{
	free(cam->horizontal);
	free(cam->vertical);
	free(cam->lower_left_corner);
	free(cam->origin);
	free(cam);
}
