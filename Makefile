CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = bsq.c \
		  check_valid.c \
		  matrix_creation.c \
		  f_open_read_list.c \
		  ft_atoi.c \
		  read_first_line.c \
		  draw_square.c

OBJECTS = $(SOURCES:.c=.o)
BINARY = bsq

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -include ft_header.h

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(BINARY)

re: fclean all
