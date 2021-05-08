# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jgalloni <jgalloni@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/04 17:20:51 by jgalloni      #+#    #+#                  #
#    Updated: 2020/11/14 15:33:35 by jgalloni      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c\
ft_memccpy.c ft_memmove.c ft_memchr.c\
ft_memcmp.c ft_strlen.c ft_strlcpy.c\
ft_strlcat.c ft_strchr.c ft_strrchr.c\
ft_strnstr.c ft_strncmp.c ft_atoi.c\
ft_isalpha.c ft_isdigit.c ft_isalnum.c\
ft_isascii.c ft_isprint.c ft_toupper.c\
ft_tolower.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_split.c ft_itoa.c ft_strmapi.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= libft.h

FLAGS	= -Wall -Wextra -Werror

AR		= ar rc

all:		$(NAME)

.c.o:
			${CC} -c ${FLAGS} $< -o ${<:.c=.o}

clean:
			${RM}  ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

$(NAME):	${OBJS}
			${AR} $(NAME) ${OBJS} ${HEADER}
