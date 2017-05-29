CC = gcc
CFLAGS =-I src -I thirdparty -Wall -Werror
TEST_FLAGS =-I src -I thirdparty -Wall -Werror
TEST_OBJ_DIR = build/test
EXECUTABLE = make
TESTEXEC = test-run
SRC_BIN = bin
SRC_BUILD_DIR = build
SRC_DIR = src


all: makedir compile mktest test-compile

makedir:
	mkdir -p bin build

compile: $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o
	$(CC) $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o -o $(SRC_BIN)/$(EXECUTABLE)

$(SRC_BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(SRC_BUILD_DIR)/main.o

$(SRC_BUILD_DIR)/deposit.o: $(SRC_DIR)/deposit.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/deposit.c -o $(SRC_BUILD_DIR)/deposit.o
test: mktest test-compile

mktest:
	mkdir -p bin build/test

test-compile: $(TEST_OBJ_DIR)/main.o $(TEST_OBJ_DIR)/deposit_test.o $(TEST_OBJ_DIR)/validation_test.o $(SRC_BUILD_DIR)/deposit.o
	$(CC) $(TEST_OBJ_DIR)/main.o $(TEST_OBJ_DIR)/deposit_test.o $(TEST_OBJ_DIR)/validation_test.o $(SRC_BUILD_DIR)/deposit.o -o $(TESTEXEC)

$(TEST_OBJ_DIR)/main.o: test/main.c
	$(CC) $(TEST_FLAGS) -c test/main.c -o $(TEST_OBJ_DIR)/main.o

$(TEST_OBJ_DIR)/deposit_test.o: test/deposit_test.c
	$(CC) $(TEST_FLAGS) -c test/deposit_test.c -o $(TEST_OBJ_DIR)/deposit_test.o

$(TEST_OBJ_DIR)/validation_test.o: test/validation_test.c
	$(CC) $(TEST_FLAGS) -c test/validation_test.c -o $(TEST_OBJ_DIR)/validation_test.o

.PHONY : clean
clean:
	rm -rf build/*.o bin/*
