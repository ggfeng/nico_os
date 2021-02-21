EXEC=test
CC      :=gcc
SRC     = main.c
SRC     += file_operation.c
SRC     += kenobi_platform.c

CFLAGS += -I ./

OBJS = $(SRC:%.c=%.o)
$(EXEC): $(OBJS)

all:
	$(CC) $(CFLAGS) $(SRC) -o test
clean:
	rm -rf *.o
	rm -rf hello
.PHONY : all
