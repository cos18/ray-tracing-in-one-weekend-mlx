/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:15:29 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/27 20:22:58 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*re;
	unsigned char	*put;
	size_t			locate;

	re = malloc(count * size);
	if (re)
	{
		locate = -1;
		put = (unsigned char *)re;
		while (++locate < count * size)
			*(put++) = 0;
	}
	return (re);
}
