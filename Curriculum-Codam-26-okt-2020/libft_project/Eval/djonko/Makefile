# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                             :+:    :+:           #
#                                                      +:+                     #
#    By: djonker <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 15:02:02 by djonker       #+#    #+#                  #
#    Updated: 2021/03/02 11:39:35 by djonker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FC			= -Wall -Werror -Wextra -c
SO			= libft.so
FL			= -shared -o
FAR			= ar -crs
RM			= rm -f
SRC			= ft_atoi.c ft_bzero.c ft_calloc.c ft_cntwrd.c ft_intlen.c \
	  			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_itoa.c ft_malstr.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memmove.c ft_memcpy.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_wrdlen.c ft_frenarr.c \
				ft_btoi.c ft_itob.c ft_revstr.c ft_frearr.c ft_putznbr.c \
				ft_strupp.c ft_strlow.c ft_power.c ft_sqrt.c ft_factor.c \
				ft_fnprim.c ft_isprim.c ft_dtoh.c ft_htod.c ft_htoi.c \
				ft_itoh.c ft_ddtoi.c ft_itodd.c ft_otoi.c ft_itoo.c ft_swap.c \
				ft_round.c ft_putznbr_fd.c ft_putzflo_fd.c ft_putzflo.c \
				ft_putstr.c ft_putnbr.c ft_putflo.c ft_putendl.c ft_putchar.c \
				ft_linlen.c ft_itof.c ft_isneg.c ft_iftof.c ft_ftoi.c \
				ft_ftoa.c ft_fround.c ft_flolen.c ft_declen.c ft_atof.c \
				ft_putflo_fd.c ft_arrlen.c ft_chrstr.c ft_cntwrds.c \
				ft_isodigit.c ft_isxdigit.c ft_malstrs.c ft_min.c ft_max.c \
				ft_lincpy.c ft_linlcpy.c ft_splits.c ft_wrdlens.c \
				ft_vamin.c ft_vamax.c
BSRC		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJ			= $(SRC:.c=.o)
BOBJ		= $(BSRC:.c=.o)

ifdef WITBON
COBJ		= $(OBJ) $(BOBJ)
else
COBJ		= $(OBJ)
endif

all:		$(NAME)

clean:
				$(RM) $(OBJ) $(BOBJ)

fclean:		clean
				$(RM) $(NAME) $(SO)

re:			fclean $(NAME)

so:			comp
				$(CC) $(FL) $(SO) $(COBJ)

comp:
				$(CC) $(FC) $(SRC) $(BSRC)

$(NAME):	$(COBJ)
				$(FAR) $(NAME) $(COBJ)

bonus:
				$(MAKE) WITBON=1 all

make:		fclean comp bonus clean

.PHONY:		all clean fclean re so bonus make
