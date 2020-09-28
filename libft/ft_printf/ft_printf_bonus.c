/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:48:45 by sunpark           #+#    #+#             */
/*   Updated: 2020/07/03 21:29:51 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_printed_num(va_list args_list, int printed)
{
	int	*save;

	save = (int *)va_arg(args_list, int *);
	*save = printed;
}

int		ft_printf(const char *format, ...)
{
	va_list	args_list;
	int		printed;

	va_start(args_list, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'n')
			{
				put_printed_num(args_list, printed);
				format += 2;
			}
			else
				printed += print_percent(&format, args_list);
		}
		else
		{
			ft_putchar_fd(*(format++), 1);
			printed += 1;
		}
	}
	va_end(args_list);
	return (printed);
}
