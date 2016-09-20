CC=gcc
COMPILER_FLAGS=-std=c90 -g -O0
LDFLAGS=$(shell pkg-config --cflags --libs check) -lc -lm -o

build_is_valid_infix: ./src/is_valid_infix.c ./test/is_valid_infix_test.c
	$(CC) $(COMPILER_FLAGS) ./src/is_valid_infix.c ./test/is_valid_infix_test.c $(LDFLAGS) ./is_valid_infix_test.exe
	./is_valid_infix_test.exe

build_is_valid_rpn: ./src/is_valid_rpn.c ./test/is_valid_rpn_test.c
	$(CC) $(COMPILER_FLAGS) ./src/is_valid_rpn.c ./test/is_valid_rpn_test.c $(LDFLAGS) ./is_valid_rpn_test.exe
	./is_valid_rpn_test.exe

test: build_is_valid_infix build_is_valid_rpn


clean:
	rm -rf ./src/*.o
	rm -rf ./test/*.o
	rm -rf $(APP)
	rm -rf *.dSYM
	rm -rf *.exe
