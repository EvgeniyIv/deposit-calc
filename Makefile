CC   = gcc
CFLAGS   = -Wall -Werror
EXECUTABLE = make
SRC_BIN = bin
SRC_BUILD_DIR = build
SRC_DIR   = src


all: makedir compile

makedir:
	mkdir -p bin build

compile: $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o
	$(CC) $(SRC_BUILD_DIR)/main.o $(SRC_BUILD_DIR)/deposit.o -o $(SRC_BIN)/$(EXECUTABLE)

$(SRC_BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(SRC_BUILD_DIR)/main.o

$(SRC_BUILD_DIR)/deposit.o: $(SRC_DIR)/deposit.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/deposit.c -o $(SRC_BUILD_DIR)/deposit.o


 .PHONY : clean
clean:
	rm -rf build/*.o bin/*
