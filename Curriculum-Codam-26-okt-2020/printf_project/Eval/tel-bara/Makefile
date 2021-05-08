# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tel-bara <tel-bara@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/28 00:17:49 by tel-bara      #+#    #+#                  #
#    Updated: 2020/12/05 21:40:49 by tel-bara      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			ft_printf_conv_utils.c \
			ft_printf_conv_more_utils.c \
			ft_printf_convert_big_hex.c \
			ft_printf_convert_char.c \
			ft_printf_convert_double_e.c \
			ft_printf_convert_double_f.c \
			ft_printf_convert_double_g.c \
			ft_printf_convert_hex.c \
			ft_printf_convert_hex_ptr.c \
			ft_printf_convert_int.c \
			ft_printf_convert_string.c \
			ft_printf_convert_u_int.c \
			ft_printf_parse_flags.c \
			ft_printf_parse_specifier.c \
			ft_printf_store_count.c \
			ft_printf_write_invalid.c \
			ft_printf_write_percentage.c \
			ft_printf_write_string.c
OBJS	=	$(SRCS:.c=.o)
LIBDIR	=	./libft/
LIBFT	=	libft.a
LIBC	=	ar -rcs
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
INCS	=	.

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBDIR)/
			cp $(LIBDIR)/$(LIBFT) $(NAME)
			${LIBC} $(NAME) $(OBJS)

$(LIBFT):
			make -C ${LIBDIR}/

%.o:		%.c
			${CC} ${FLAGS} -c -I${INCS} $< -o $@

clean:
			${RM} $(OBJS)
			make clean -C ${LIBDIR}

fclean:		clean
			${RM} $(NAME) $(LIBDIR)${LIBFT}

re:			fclean all

bonus:		$(NAME)

.PHONY:		all .c.o clean fclean re bonus
