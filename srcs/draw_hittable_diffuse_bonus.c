/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable_diffuse_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/23 13:31:02 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec				*get_recursive_color(t_list *lst, t_hitlst_info **info,
											int depth, int *is_free)
{
	t_vec			*target;
	t_ray			*ray;
	t_vec			*tmp;
	double			t;

	if (depth <= 0)
		return (vec_create(0, 0, 0));
	if (hitlst_hit(lst, *info))
	{
		target = vec_add_apply(vec_random_in_hemisphere((*info)->rec->normal),
								(*info)->rec->p);
		tmp = vec_dup((*info)->rec->p);
		ray = ray_create(tmp, vec_sub_apply(target, (*info)->rec->p));
		free_hitlst_info(*info, *is_free);
		*is_free = TRUE;
		*info = hitlst_info_new(ray);
		return (vec_mul_const_apply(get_recursive_color(lst, info, depth - 1,
															is_free), 0.5));
	}
	t = 0.5 * ((vec_unit_apply((*info)->ray->dir))->y + 1.0);
	target = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
	tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(target, tmp);
	free(tmp);
	return (target);
}

void				get_hittable_diffuse_color(t_list *lst,
												t_hitlst_info **info,
												t_vec *color)
{
	t_vec			*target;
	int				is_free;

	is_free = FALSE;
	target = get_recursive_color(lst, info, REFLECT_DEPTH, &is_free);
	vec_add_apply(color, target);
	free(target);
	free_hitlst_info(*info, is_free);
}

void				draw_hittable_diffuse_anti(t_camera *cam, t_list *lst)
{
	int				x;
	int				y;
	int				locate;
	t_vec			*color;
	t_hitlst_info	*lst_info;

	y = cam->data->height;
	while ((--y) >= 0)
	{
		x = -1;
		while ((++x) < cam->data->width)
		{
			color = vec_create(0, 0, 0);
			locate = -1;
			while ((++locate) < ANTI_SAMPLES)
			{
				lst_info = get_hitlst_by_locate(x, y, cam);
				get_hittable_diffuse_color(lst, &lst_info, color);
			}
			cam->data->img[x][y] = get_color_sample_gamma(color);
			free(color);
		}
	}
}
