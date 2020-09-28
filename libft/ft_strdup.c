/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:24:33 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/27 20:29:24 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*re;
	size_t	locate;

	re = (char *)malloc(ft_strlen(s1) + 1);
	if (re)
	{
		locate = -1;
		while (++locate < ft_strlen(s1))
			re[locate] = s1[locate];
		re[locate] = '\0';
	}
	return (re);
}
