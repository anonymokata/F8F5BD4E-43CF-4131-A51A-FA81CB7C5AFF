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

build_infix_to_rpn: ./src/is_valid_infix.c ./src/valid_infix_to_rpn.c ./src/infix_to_rpn.c ./test/infix_to_rpn_test.c ./src/rpn_infix_utilities.c
	$(CC) $(COMPILER_FLAGS) ./src/is_valid_infix.c ./src/valid_infix_to_rpn.c ./src/infix_to_rpn.c ./test/infix_to_rpn_test.c ./src/rpn_infix_utilities.c $(LDFLAGS) ./infix_to_rpn.exe
	./infix_to_rpn.exe

build_rpn_to_infix: ./src/is_valid_rpn.c ./src/valid_rpn_to_infix.c ./src/rpn_to_infix.c ./test/rpn_to_infix_test.c ./src/rpn_infix_utilities.c
		$(CC) $(COMPILER_FLAGS) ./src/is_valid_rpn.c ./src/valid_rpn_to_infix.c ./src/rpn_to_infix.c ./test/rpn_to_infix_test.c ./src/rpn_infix_utilities.c $(LDFLAGS) ./rpn_to_infix.exe
		./rpn_to_infix.exe

test: clean build_is_valid_infix build_is_valid_rpn build_valid_rpn_to_infix build_valid_infix_to_rpn build_infix_to_rpn build_rpn_to_infix

clean:
	rm -rf ./src/*.o
	rm -rf ./test/*.o
	rm -rf $(APP)
	rm -rf *.dSYM
	rm -rf *.exe
