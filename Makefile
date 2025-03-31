CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = repl.c inputbuffer.c metacommands.c statements.c
OBJ = $(SRC:.c=.o)
TARGET = mydb

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

