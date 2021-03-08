CC = gcc
CPPFLAGS = -I. -D_DEFAULT_SOURCE
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

VPATH = tests:src

LIB-OBJS = \
<<<<<<< HEAD
    lexer.o \
    queue.o \
    token.o \
    my_atoi_itoa_base.o \
    my_readline.o \
    help_message.o \
    my_getopt.o \
    my_string.o \

LIB = libevalexpr.so
=======
    my_string.o \
    my_readline.o
>>>>>>> my_readline

LIB = libevalexpr.so
BIN = main
OBJ = main.o

TESTS-LDLIBS = \
	-lcriterion \
	-L. -levalexpr

TESTS-LDFLAGS = \
	-Wl,-rpath,.

TESTS-OBJS = \
    test-my_readline.o \
    #test-my_string.o 

<<<<<<< HEAD
all: $(LIB)
=======
all: $(LIB) $(BIN)
$(LIB): CFLAGS += -fsanitize=address -fPIC
$(LIB): LDLIBS += -lasan
>>>>>>> my_readline
$(LIB): $(LIB-OBJS)
$(BIN): $(OBJ)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)

debug: CFLAGS += -fsanitize=address -g
debug: LDLIBS += -lasan
debug: clean all

check: all testsuite 
	./testsuite  --verbose --tap
testsuite: $(TESTS-OBJS)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)

clean:
	$(RM) testsuite $(TESTS-OBJS) $(LIB) $(LIB-OBJS) $(BIN) $(OBJ)

.PHONY: all check clean

%.so: 
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LDLIBS)
