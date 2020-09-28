/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:49:32 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:16:55 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	locate;

	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		locate = 0;
		while ((locate + 1) < dstsize && src[locate] != '\0')
		{
			dst[locate] = src[locate];
			locate++;
		}
		dst[locate] = '\0';
	}
	return (ft_strlen(src));
}
