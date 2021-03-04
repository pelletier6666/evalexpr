CC = gcc
CPPFLAGS = -I. -D_DEFAULT_SOURCE
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

VPATH = tests:src

LIB-OBJS = \
    lexer.o \
    queue.o \
    token.o \
    my_atoi_itoa_base.o \
    my_readline.o \
    help_message.o \
    my_getopt.o \
    my_string.o \

LIB = libevalexpr.so


TESTS-LDLIBS = \
	-lcriterion \
	-L. -levalexpr\

TESTS-LDFLAGS = \
	-Wl,-rpath,.

TESTS-OBJS = test-my_string.o

all: $(LIB)
$(LIB): $(LIB-OBJS)

debug: CFLAGS += -fsanitize=address -g
debug: LDLIBS += -lasan
debug: clean all

check: all testsuite 
	./testsuite  --verbose --tap
testsuite: $(TESTS-OBJS)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)

clean:
	$(RM) testsuite $(TESTS-OBJS) $(LIB) $(LIB-OBJS)

.PHONY: all check clean

%.so: 
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LDLIBS)
