/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:05:38 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/27 17:16:24 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*recur(char *now, int c)
{
	char	*next;

	next = ft_strchr(now + 1, c);
	if (next == NULL)
		return (now);
	return (recur(next, c));
}

char		*ft_strrchr(const char *s, int c)
{
	char	*first;

	if (c == '\0')
		return (ft_strchr(s, c));
	first = ft_strchr(s, c);
	if (first == NULL)
		return (NULL);
	return (recur(first, c));
}
