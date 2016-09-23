CC=gcc
COMPILER_FLAGS=-std=c90 -g -O0
LDFLAGS=$(shell pkg-config --cflags --libs check) -lc -lm -o

build_is_valid_infix: ./src/is_valid_infix.c ./test/is_valid_infix_test.c ./src/rpn_infix_utilities.c
	$(CC) $(COMPILER_FLAGS) ./src/is_valid_infix.c ./test/is_valid_infix_test.c  ./src/rpn_infix_utilities.c $(LDFLAGS) ./is_valid_infix_test.exe
	./is_valid_infix_test.exe

build_is_valid_rpn: ./src/is_valid_rpn.c ./test/is_valid_rpn_test.c ./src/rpn_infix_utilities.c
	$(CC) $(COMPILER_FLAGS) ./src/is_valid_rpn.c ./test/is_valid_rpn_test.c ./src/rpn_infix_utilities.c $(LDFLAGS) ./is_valid_rpn_test.exe
	./is_valid_rpn_test.exe

build_valid_rpn_to_infix: ./src/valid_rpn_to_infix.c ./test/valid_rpn_to_infix_test.c ./src/rpn_infix_utilities.c
	$(CC) $(COMPILER_FLAGS) ./src/valid_rpn_to_infix.c ./test/valid_rpn_to_infix_test.c ./src/rpn_infix_utilities.c $(LDFLAGS) ./valid_rpn_to_infix.exe
	./valid_rpn_to_infix.exe

build_valid_infix_to_rpn: ./src/valid_infix_to_rpn.c ./test/valid_infix_to_rpn_test.c ./src/rpn_infix_utilities.c
	$(CC) $(COMPILER_FLAGS) ./src/valid_infix_to_rpn.c ./test/valid_infix_to_rpn_test.c ./src/rpn_infix_utilities.c $(LDFLAGS) ./valid_infix_to_rpn.exe
	./valid_infix_to_rpn.exe

test: clean build_is_valid_infix build_is_valid_rpn build_valid_rpn_to_infix build_valid_infix_to_rpn

clean:
	rm -rf ./src/*.o
	rm -rf ./test/*.o
	rm -rf $(APP)
	rm -rf *.dSYM
	rm -rf *.exe
