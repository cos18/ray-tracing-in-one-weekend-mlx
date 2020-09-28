/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:48:48 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 19:25:59 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	locate;

	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		locate = len;
		while (--locate < len)
			((unsigned char *)dst)[locate] = ((unsigned char *)src)[locate];
	}
	else
		ft_memcpy(dst, src, len);
	(void)locate;
	return (dst);
}
