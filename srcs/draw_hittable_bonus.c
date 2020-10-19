/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:55:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/18 20:57:28 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_hitlst_info		*get_hitlst_by_locate(int x, int y, t_camera *cam)
{
	double			u;
	double			v;
	t_ray			*ray;

	u = ((double)x + random_double()) / (cam->data->width - 1);
	v = ((double)y + random_double()) / (cam->data->height - 1);
	ray = camera_get_ray(cam, u, v);
	return (hitlst_info_new(ray));
}

void				get_hittable_color(t_list *lst, t_hitlst_info *info,
											t_vec *color)
{
	t_vec			*cal_color;
	t_vec			*tmp;
	double			t;

	if (hitlst_hit(lst, info))
	{
		cal_color = vec_add_apply(vec_create(1, 1, 1), info->rec->normal);
		vec_mul_const_apply(cal_color, 0.5);
	}
	else
	{
		tmp = vec_unit(info->ray->dir);
		t = 0.5 * (tmp->y + 1.0);
		free(tmp);
		cal_color = vec_mul_const_apply(vec_create(1, 1, 1), 1.0 - t);
		tmp = vec_mul_const_apply(vec_create(0.5, 0.7, 1), t);
		vec_add_apply(cal_color, tmp);
		free(tmp);
	}
	vec_div_const_apply(cal_color, ANTI_SAMPLES);
	vec_add_apply(color, cal_color);
	free(cal_color);
}

void				draw_hittable_anti(t_camera *cam, t_list *lst)
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
				get_hittable_color(lst, lst_info, color);
				free_hitlst_info(lst_info, FALSE);
			}
			cam->data->img[x][y] = get_color_val(color);
			free(color);
		}
	}
}
