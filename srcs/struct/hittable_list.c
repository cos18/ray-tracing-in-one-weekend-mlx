/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:29:29 by sunpark           #+#    #+#             */
/*   Updated: 2020/10/10 16:35:20 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*hittable_new()
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	result->content = NULL;
	result->next = NULL;
	return (result);
}

void	hittable_add(t_list *lst, void *obj)
{
	if (lst->content == NULL)
	{
		
	}
}
