NAME = libftprintf.a
LIBFT = libft/libft.a
SRCS = printf.c utils.c parse_flags.c conversions.c width_handler.c hexa_and_unsigned.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Werror -Wextra -Wall
AR		= ar rc

all : $(NAME)

$(LIBFT) :
	@tput -Txterm setaf 2
	@echo "MAKING : LIBFT"
	@tput -Txterm setaf 5
	cd libft; make
	cp libft/libft.a ./$(NAME)

.c.o: $(SRCS)
	@tput -Txterm setaf 2
	@echo "COMPILING : $<"
	@tput -Txterm setaf 4
	gcc -c $(FLAGS) $< -o $(<:.c=.o)

clean_libft :
	@tput -Txterm setaf 2
	@echo "CLEANING : LIBFT"
	@tput -Txterm setaf 5
	cd libft; make clean;

clean :  clean_libft
	@tput -Txterm setaf 2
	@echo "CLEANING : FTPRINTF"
	@tput -Txterm setaf 4
	rm -f $(OBJS)
	@tput -Txterm setaf 7

fclean : clean
	@tput -Txterm setaf 2
	@echo "FCLEAN : LIBFT"
	@tput -Txterm setaf 5
	rm -f $(LIBFT)
	@tput -Txterm setaf 2
	@echo "FCLEAN : FTPRINTF"
	@tput -Txterm setaf 4
	rm -f $(NAME)
	@tput -Txterm setaf 7

re : fclean all 

$(NAME):	$(OBJS) $(LIBFT)
	@tput -Txterm setaf 2
	@echo "CREATING libftprintf.a"
	@tput -Txterm setaf 4
	$(AR) $(NAME) $(OBJS)
	@tput -Txterm setaf 7