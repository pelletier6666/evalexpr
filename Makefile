CC = gcc
CPPFLAGS = -I. -D_DEFAULT_SOURCE
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g -fsanitize=leak

LDFLAGS = -fprofile-arcs
#LDLIBS = -llsan -L. -levalexpr

VPATH = tests:src

LIB-OBJS = \
    lexer.o \
    my_readline.o \
    my_string.o \
    queue.o \
    token.o \
    my_atoi_itoa_base.o \
    help_message.o \
    my_getopt.o \
    my_getopt_utils.o

LIB = libevalexpr.so

OBJ = main.o
BIN = main

LDLIBS = -llsan \

LDFLAGS = -fsanitize=leak \
	  -Wl,-rpath,.
TESTS-OBJS = \
	test-my_readline.o \
	test-my_string.o \
	test-my_getopt.o \
	test-my_atoi_itoa_base.o \
	#test-token.o \
	test-queue.o \
	test-lexer.o


all: $(LIB) $(BIN)
$(LIB): CFLAGS += -fPIC
$(LIB): $(LIB-OBJS)

$(BIN): CFLAGS += -fsanitize=address
$(BIN): LDLIBS += -lasan -L. -levalexpr
$(BIN): $(OBJ)

debug: clean all

check: debug testsuite 
	LSAN_OPTIONS="leak=1" ./testsuite  --verbose

testsuite: LDLIBS += -L. -levalexpr -lcriterion
testsuite: $(TESTS-OBJS)
	$(LINK.o) $^ $(LDFLAGS) -o $@ $(LDLIBS)

clean:
	$(RM) $(TESTS-OBJS) testsuite $(OBJ) $(BIN) $(LIB) $(LIB-OBJS)

.PHONY: all check clean

%.so: 
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LDLIBS)
