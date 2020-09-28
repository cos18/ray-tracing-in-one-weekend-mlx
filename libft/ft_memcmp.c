/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:39:22 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:15:39 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	locate;

	if (!n)
		return (0);
	locate = -1;
	while (++locate < n)
	{
		if (((unsigned char *)s1)[locate] != ((unsigned char *)s2)[locate])
			break ;
	}
	if (locate == n)
		return (0);
	return (((unsigned char *)s1)[locate] - ((unsigned char *)s2)[locate]);
}
