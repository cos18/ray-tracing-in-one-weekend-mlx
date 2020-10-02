/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:06:38 by sunpark           #+#    #+#             */
/*   Updated: 2020/09/28 16:18:53 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_trgb(int t, t_vec *color)
{
	return (t << 24 | (int)(color->x) << 16 |
		(int)(color->y) << 8 | (int)(color->z));
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

t_vec	*get_color(int trgb)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = trgb & (0xFF << 16);
	result->y = trgb & (0xFF << 8);
	result->z = trgb & 0xFF;
	return (result);
}
