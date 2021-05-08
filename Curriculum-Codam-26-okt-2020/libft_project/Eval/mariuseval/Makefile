# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2020/11/01 17:18:35 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft

BONUSFILES		= ft_lst*
MOREBONUS		= *_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCEXT			= c
SRCDIR			= .
HEADERDIR		= .
OBJEXT			= o
BUILDDIR		= obj
BINDIR			= bin

SOURCES			= $(shell find '$(SRCDIR)/' -type f $\
-name '*.$(SRCEXT)' -a $\
-not -name '$(BONUSFILES).$(SRCEXT)' -a $\
-not -name '$(MOREBONUS).$(SRCEXT)')
BONUSSOURCES	= $(shell find '$(SRCDIR)/' -type f $\
-name '$(BONUSFILES).$(SRCEXT)' -o $\
-name '$(MOREBONUS).$(SRCEXT)')
OBJECTS			= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, $\
$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
BONUSOBJECTS	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, $\
$(BONUSSOURCES:.$(SRCEXT)=.$(OBJEXT)))

all: $(NAME)

$(NAME): $(NAME).a

$(NAME).a: $(BUILDDIR)/ $(OBJECTS)
	ar -cr $(NAME).a $(OBJECTS)

bonus: $(BUILDDIR)/ $(OBJECTS) $(BONUSOBJECTS)
	ar -cr $(NAME).a $(OBJECTS) $(BONUSOBJECTS)

so $(NAME).so: $(BUILDDIR)/ $(OBJECTS)
	$(CC) $(CFLAGS) -shared $(BUILDDIR)/*.$(OBJEXT) -o $(NAME).so

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(NAME).a $(NAME).so

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@

.PHONY: all clean fclean re so bonus
