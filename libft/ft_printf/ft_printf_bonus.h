/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:42:45 by sunpark           #+#    #+#             */
/*   Updated: 2020/07/04 13:33:17 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_percent
{
	int			sort;
	int			sign;
	int			width;
	int			precision;
}				t_percent;

int				print_percent(const char **format, va_list args_list);

t_percent		*create_percent(void);
void			set_sort(t_percent *p, char c);
void			set_sign(t_percent *p, char c);
void			clear_percent(t_percent *p);

int				print_sort(t_percent *p, int len);
int				print_char(t_percent *p, va_list ap);
int				print_string(t_percent *p, va_list ap);
int				print_real_percent(t_percent *p);
int				print_int(t_percent *p, va_list ap);
int				print_unint(t_percent *p, va_list ap);
int				print_pointer(t_percent *p, va_list ap);
int				print_hex(t_percent *p, va_list ap, int is_upper);

#endif
