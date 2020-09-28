/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:31:19 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:13:58 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	locate;

	if (!dst && !src)
		return (dst);
	locate = 0;
	while (locate < n)
	{
		((unsigned char *)dst)[locate] = ((unsigned char *)src)[locate];
		if (((unsigned char *)dst)[locate] == (unsigned char)c)
			break ;
		locate++;
	}
	if (locate == n)
		return ((void *)0);
	return (dst + locate + 1);
}
