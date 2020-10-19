/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_material.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:08:27 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/19 15:46:29 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATERIAL_H
# define MINIRT_MATERIAL_H

#include "minirt_struct.h"

t_material	*mat_lambertian_new(t_vec *color);
int			lambertian_scatter(t_material *mat, t_ray *ray_in,
								t_hit_record *rec, t_material_info *info);
t_material	*mat_metal_new(t_vec *color, double fuzz);
int			metal_scatter(t_material *mat, t_ray *ray_in, t_hit_record *rec,
						t_material_info *info);


#endif
