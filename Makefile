CC = gcc
CPPFLAGS = -I. -D_DEFAULT_SOURCE
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

VPATH = tests:src

LIB-OBJS = \
    my_string.o \
    my_readline.o

LIB = libevalexpr.so
BIN = main
OBJ = main.o

TESTS-LDLIBS = \
	-lasan \
	-lcriterion \
	-L. -levalexpr

TESTS-LDFLAGS = \
	-Wl,-rpath,.

TESTS-OBJS = \
    test-my_readline.o \
    #test-my_string.o 

all: $(LIB) $(BIN)
$(LIB): CFLAGS += -fsanitize=address -fPIC
$(LIB): LDLIBS += -lasan
$(LIB): $(LIB-OBJS)
$(BIN): $(OBJ)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)


debug: clean all

check: debug testsuite 
	./testsuite  --verbose
testsuite: $(TESTS-OBJS)
	$(LINK.o) $^ $(TESTS-LDFLAGS) -o $@ $(TESTS-LDLIBS)

clean:
	$(RM) testsuite $(TESTS-OBJS) $(LIB) $(LIB-OBJS) $(BIN) $(OBJ)

.PHONY: all check clean

%.so: 
	$(CC) -shared $(LDFLAGS) -o $@ $^ $(LDLIBS)
