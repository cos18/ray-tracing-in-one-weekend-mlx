/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:42:18 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/17 16:55:30 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt.h"

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

#endif
