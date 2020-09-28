/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:53:26 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:21:00 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	locate;
	size_t	totsize;

	if (!s)
		return (NULL);
	locate = ft_strlen(s);
	if (locate <= start)
	{
		result = (char *)malloc(1);
		*result = '\0';
		return (result);
	}
	totsize = ft_strlen(s + start);
	totsize = (totsize > len) ? len : totsize;
	result = (char *)malloc(totsize + 1);
	if (result)
	{
		locate = -1;
		while (++locate < totsize)
			result[locate] = s[start + locate];
		result[locate] = '\0';
	}
	return (result);
}
