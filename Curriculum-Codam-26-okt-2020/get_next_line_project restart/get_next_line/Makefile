#
# Compiler flags
#
CC     = gcc
CFLAGS = -Wall -Wextra -Werror

#
# Project files
#
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)
EXE  = get_next_line
DBGEXE = debug_get_next_line

#
# Project dirs
#
SRC_DIR := .

#
# Release build settings
#
RELDIR = .
RELEXE = $(RELDIR)/$(EXE)
RELOBJS = $(addprefix $(SRC_DIR)/, $(OBJS))
RELCFLAGS = -D BUFFER_SIZE=32

all: release

#
# Debug rules
#
DBGDIR = .
DGBEXE = $(DGBDIR)/$(EXE)
DBGOBJS = $(addprefix $(SRC_DIR)/, $(OBJS))
DBGCFLAGS = -g -D BUFFER_SIZE=32

debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJS)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $(DBGEXE) $^

$(DBGDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<

#
# Release rules
#
release: $(RELEXE)

$(RELEXE): $(RELOBJS) | $(RELDIR)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $(RELEXE) $^

$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<

re: clean all

clean:
	rm -f $(RELOBJS) $(DBGOBJS)

fclean:
	rm -f $(RELEXE) $(DBGEXE) $(DBGOBJ) $(RELOBJS)

.PHONY: all clean debug release re fclean
