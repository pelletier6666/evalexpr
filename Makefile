CC = gcc
CPPFLAGS = -I. -D_DEFAULT_SOURCE
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

VPATH = tests:src

LIB-OBJS = my_string.o
LIB = libevalexpr.so


TESTS-LDLIBS = \
	-lasan \
	-lcriterion \
	-L. -levalexpr\

TESTS-LDFLAGS = \
	-Wl,-rpath,.

TESTS-OBJS = test-my_string.o

all: $(LIB)
$(LIB): CFLAGS += -fsanitize=address
$(LIB): LDLIBS += -lasan
$(LIB): $(LIB-OBJS)


debug: clean all

check: debug testsuite 
	./testsuite  --verbose
testsuite: $(TESTS-OBJS)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)

clean:
	$(RM) testsuite $(TESTS-OBJS) $(LIB) $(LIB-OBJS)

.PHONY: all check clean

%.so: 
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LDLIBS)
