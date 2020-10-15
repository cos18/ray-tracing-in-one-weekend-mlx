/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 10:33:13 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/15 16:45:02 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	vec_div_const_apply(result->horizontal, 2.0);
	vec_div_const_apply(result->vertical, 2.0);
	tmp = vec_create(0, 0, focal_length);
	vec_add_apply(tmp, result->horizontal);
	vec_add_apply(tmp, result->vertical);
	result->lower_left_corner = vec_sub(result->origin, tmp);
	free(tmp);
	vec_mul_const_apply(result->horizontal, 2.0);
	vec_mul_const_apply(result->vertical, 2.0);
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
