##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile with the folling rules: re, clean and fclean rules
##

CC = gcc

SRC = src/main.c \
	src/validate_script.c \
	src/window.c \
	src/cleanup.c \
	src/extract_data.c \
	src/lib/my_atoi.c \
	src/lib/my_fgets.c \
	src/lib/my_isdigit.c \
	src/lib/my_isspace.c \
	src/lib/my_memcpy.c \
	src/lib/my_put_error.c \
	src/lib/my_putchar.c \
	src/lib/my_putstr.c \
	src/lib/my_realloc.c \
	src/lib/my_strcmp.c \
	src/lib/my_strcpy.c \
	src/lib/my_strdup.c \
	src/lib/my_strlen.c \
	src/lib/my_strtok.c \
	src/sprites/init_sprites.c \
	src/sprites/planes.c \

OBJ = $(SRC:.c=.o)

NAME = my_radar

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -g

$(NAME): $(OBJ)
	$(CC)	-o	$(NAME)	$(OBJ)	$(LDFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
