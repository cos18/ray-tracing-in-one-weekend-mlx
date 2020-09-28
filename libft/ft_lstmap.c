/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:26:05 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:13:24 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*after;
	t_list	*now;

	result = NULL;
	now = lst;
	while (now)
	{
		after = ft_lstnew((*f)(now->content));
		if (!after)
			break ;
		ft_lstadd_back(&result, after);
		now = now->next;
	}
	if (ft_lstsize(lst) != ft_lstsize(result))
		ft_lstclear(&result, del);
	return (result);
}
