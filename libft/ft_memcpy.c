/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:24:18 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 14:47:42 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	while (len--)
	{
		*d = *((unsigned char *)src);
		d++;
		src++;
	}
	return (dst);
}
