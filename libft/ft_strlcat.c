/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:55:54 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:17:35 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	strsize[2];
	size_t	cat_lo;

	strsize[0] = ft_strlen(dst);
	strsize[1] = ft_strlen(src);
	if (strsize[0] + 1 < dstsize)
	{
		while (*dst)
			dst++;
		cat_lo = 0;
		while ((cat_lo < dstsize - strsize[0] - 1) && src[cat_lo])
		{
			*(dst) = src[cat_lo];
			dst++;
			cat_lo++;
		}
		*dst = '\0';
	}
	if (strsize[0] > dstsize)
		return (strsize[1] + dstsize);
	return (strsize[0] + strsize[1]);
}
