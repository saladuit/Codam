# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2020/11/16 10:09:13 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
AR =		ar
FILES = 	libft.h
CC = 		gcc
RM =		rm -f
CFLAGS = 	-Wall -Wextra -Werror
O_FILES = 	$(SRC:.c=.o)
SRC = 		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_itoa.c ft_memccpy.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memchr.c ft_memset.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
			ft_strchr.c ft_strrchr.c ft_strdup.c ft_strjoin.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
			ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c\
			ft_tolower.c ft_toupper.c
BONUS =		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c
BO_FILES =	$(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) rc $(NAME) $(O_FILES)

$(O_FILES): $(H_FILES)
	$(CC) $(CFLAGS) -c $(SRC)

bonus: $(O_FILES) $(BO_FILES)
	$(AR) rc $(NAME) $(O_FILES) $(BO_FILES)

clean:
	$(RM) $(O_FILES) $(BO_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
