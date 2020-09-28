/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:56:06 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:14:17 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	locate;
	void	*find;

	locate = -1;
	find = (void *)s;
	while (++locate < n)
	{
		if (*((unsigned char *)find) == (unsigned char)c)
			break ;
		find++;
	}
	if (locate == n)
		return (NULL);
	return (find);
}
