target = app
src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

CPPFLAGS = 	-c -g -Wall -std=c99
CFLAGS = -I include
CC = gcc

$(target):$(obj)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	-rm -f $(obj)
	-rm -f $(target)
