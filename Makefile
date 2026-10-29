CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99
TARGET = shitfetch
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o bin/$(TARGET)

clean:
	rm -rf bin/

.PHONY: all clean
