CC=gcc
COMPILER_FLAGS=-std=c90 -g -O0
LDFLAGS=$(shell pkg-config --cflags --libs check) -lc -lm -o
APP=./rpn_converter_test
SOURCES=./src/is_valid_infix.c
TESTS=./test/is_valid_infix_test.c

build: $(SOURCES) $(TESTS)
	$(CC) $(COMPILER_FLAGS) $(SOURCES) $(TESTS) $(LDFLAGS) $(APP)

test: build
	$(APP)

clean:
	rm -rf ./src/*.o
	rm -rf ./test/*.o
	rm -rf $(APP)
	rm -rf *.dSYM
