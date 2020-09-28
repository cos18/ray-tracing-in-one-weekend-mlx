/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_percentage_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:20 by sunpark           #+#    #+#             */
/*   Updated: 2020/07/03 21:31:13 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		get_char_num(char c)
{
	if (c == '-' || c == '0')
		return (1);
	if (c == ' ' || c == '+')
		return (2);
	if (c == '*' || ft_isdigit(c))
		return (3);
	if (c == '.')
		return (4);
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (5);
	return (0);
}

int		get_p_num(const char **format, va_list args_list)
{
	char		*numstr;
	const char	*first;
	size_t		len;
	int			result;

	if (**format == '*')
	{
		result = va_arg(args_list, int);
		++(*format);
		return (result);
	}
	len = 0;
	while (**format == '0')
		++(*format);
	first = *format;
	while (ft_isdigit(**format))
	{
		len++;
		++(*format);
	}
	numstr = ft_strndup(first, len);
	result = ft_atoi(numstr);
	free(numstr);
	return (result);
}

void	assign_p(t_percent *now, const char **format, va_list args_list)
{
	if (get_char_num(**format) == 1 || get_char_num(**format) == 2)
	{
		(get_char_num(**format) == 1 ? \
			set_sort(now, **format) : set_sign(now, **format));
		(*format)++;
	}
	else if (get_char_num(**format) == 3)
	{
		now->width = get_p_num(format, args_list);
		if (now->width < 0)
		{
			now->width *= -1;
			set_sort(now, '-');
		}
	}
	else
	{
		++(*format);
		if (get_char_num(**format) == 3 || **format == '0')
			now->precision = get_p_num(format, args_list);
		else
			now->precision = 0;
		if (now->precision < 0)
			now->precision = -1;
	}
}

int		print_p(t_percent *now, const char **format, va_list args_list)
{
	int	result;

	result = 0;
	if (**format == 'c')
		result = print_char(now, args_list);
	else if (**format == 's')
		result = print_string(now, args_list);
	else if (**format == '%')
		result = print_real_percent(now);
	else if (**format == 'd' || **format == 'i')
		result = print_int(now, args_list);
	else if (**format == 'u')
		result = print_unint(now, args_list);
	else if (**format == 'x' || **format == 'X')
		result = print_hex(now, args_list, (**format == 'X' ? TRUE : FALSE));
	else
		result = print_pointer(now, args_list);
	(*format)++;
	return (result);
}

int		print_percent(const char **format, va_list args_list)
{
	int			status;
	int			printed;
	t_percent	*now;

	printed = 0;
	status = 1;
	now = create_percent();
	(*format)++;
	while (**format)
	{
		if (!get_char_num(**format))
			break ;
		if (status > 2 && status > get_char_num(**format))
			clear_percent(now);
		status = get_char_num(**format);
		if (status == 5)
		{
			printed = print_p(now, format, args_list);
			break ;
		}
		else
			assign_p(now, format, args_list);
	}
	free(now);
	return (printed);
}
