/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:06:38 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/09 21:25:00 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_trgb(int t, t_vec *color)
{
	int	x;
	int	y;
	int	z;

	x = (color->x > 255) ? 255 : color->x;
	x = (x < 0) ? 0 : x;
	y = (color->y > 255) ? 255 : color->y;
	y = (y < 0) ? 0 : y;
	z = (color->z > 255) ? 255 : color->z;
	z = (z < 0) ? 0 : z;
	return (t << 24 | x << 16 | y << 8 | z);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

t_vec	*get_color(int trgb)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = (trgb & (0xFF << 16)) >> 16;
	result->y = (trgb & (0xFF << 8)) >> 8;
	result->z = trgb & 0xFF;
	return (result);
}
