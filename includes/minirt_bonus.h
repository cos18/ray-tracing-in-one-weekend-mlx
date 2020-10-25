/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:42:18 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/25 12:03:25 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt.h"
# include <pthread.h>

double			random_double(void);
double			random_double_range(double min, double max);

t_vec			*vec_random_range(double min, double max);
t_vec			*vec_random_in_unit_sphere(void);
t_vec			*vec_random_unit(void);
t_vec			*vec_random_in_hemisphere(t_vec *normal);

int				get_color_sample_gamma(t_vec *color);

t_hitlst_info	*get_hitlst_by_locate(int x, int y, t_camera *cam);
void			draw_hittable_anti(t_camera *cam, t_list *lst);

void			draw_hittable_diffuse_anti(t_camera *cam, t_list *lst);

t_vec			*get_sky_color_t(double t);
t_vec			*get_recur_mat_color(t_list *lst, t_hitlst_info **info,
											int depth, int *is_free);
void			get_hittable_material_color(t_list *lst,
											t_hitlst_info *info,
											t_vec *color);
void			draw_hittable_material(t_camera *cam, t_list *lst);

void			draw_hittable_pthread(t_camera *cam, t_list *lst);

#endif
