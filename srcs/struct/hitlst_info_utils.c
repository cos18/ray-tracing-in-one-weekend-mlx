/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 04:25:55 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/14 05:45:25 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hitlst_info		*hitlst_info_new(t_ray *r, double t_min, double t_max,
									t_hit_record *rec)
{
	t_hitlst_info	*result;

	result = (t_hitlst_info *)malloc(sizeof(t_hitlst_info));
	result->ray = r;
	result->t_max = t_max;
	result->t_min = t_min;
	result->rec = rec;
	return (result);
}

void				free_hitlst_info(t_hitlst_info *info)
{
	ray_free(info->ray, FALSE);
	free_hit_record(info->rec);
	free(info);
}
