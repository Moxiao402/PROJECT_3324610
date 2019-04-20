SRCS = $(wildcard ./src/*.c *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
INCLUDES = -I ./include
CCFLAGS = -g -Wall -O0
OUTPUT = SimpleEncrypter
all:$(OUTPUT)
$(OUTPUT) : $(OBJS)
	@echo $(SRCS)
	$(CC) $^ -o $@ $(INCLUDES)
%.o : %.c
	$(CC) -c $< $(CCFLAGS)
.PHONY:clean
