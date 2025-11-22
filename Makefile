CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRC = src/main.c src/app.c src/menu.c src/storage.c
OUT = build/password_manager

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f build/password_manager
