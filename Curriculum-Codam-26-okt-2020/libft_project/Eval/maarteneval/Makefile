# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/24 19:18:03 by mraasvel      #+#    #+#                  #
#    Updated: 2020/10/30 09:51:35 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re
all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar rc $(LIBNAME) $^
%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(LIBNAME)
re: fclean all


# BONUS
bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(LIBNAME) $^
