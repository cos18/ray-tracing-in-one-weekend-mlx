# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunpark <sunpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/04 13:34:20 by sunpark           #+#    #+#              #
#    Updated: 2020/10/14 05:38:01 by sunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c color.c draw_basic.c mlx_utils.c img_data_utils.c save_bmp.c \
		draw_hittable.c \
		object/sky.c object/sky_ray.c object/sphere.c object/simple_sphere.c \
		object/sphere_hit.c \
		struct/vector_calc.c struct/vector_utils.c struct/ray_utils.c \
		struct/vector_apply.c struct/hit_record.c struct/hittable_utils.c \
		struct/hitlst_utils.c struct/hitlst_info_utils.c

CSRC	= ch2.c ch4.c ch5.c ch6.c
SRCDIR	= ./srcs/
CSRCDIR	= ./chapter/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
CSRCS	= $(addprefix $(CSRCDIR), $(CSRC))
OBJS	= $(SRCS:.c=.o)
COBJS	= $(CSRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME	= libft.a
MLXDIR	= ./mlx/
MLXNAME	= libmlx.dylib

NAME	= one_week

GCC		= gcc
GCCFLAG	= -Wall -Wextra -Werror
RM		= rm -f

%.o:		%.c
			$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME) $(MLXNAME) $(OBJS) $(COBJS)
			$(GCC) $(GCCFLAG) -I$(INCDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(COBJS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
			@$(MAKE) -C $(LIBDIR) bonus
			@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

$(MLXNAME):
			@$(MAKE) -C $(MLXDIR)
			@cp $(addprefix $(MLXDIR), $(MLXNAME)) $(MLXNAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(COBJS) *.bmp

fclean:		clean
			$(RM) $(NAME) $(LIBNAME) $(MLXNAME)
			@$(MAKE) -C $(LIBDIR) fclean
			@$(MAKE) -C $(MLXDIR) clean

re:			fclean all

.PHONY:		all clean fclean re
