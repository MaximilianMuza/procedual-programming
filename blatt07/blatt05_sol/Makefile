
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm

all: blatt05_1.exe
	./blatt05_1.exe

%.exe:%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
