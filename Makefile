##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile 102architect
##

SRC = src/main.c \
	src/my_lib.c \

OBJ = $(SRC:.c=.o)

NAME = 102architect

LIBFLAG = gcc -o

CFLAG = -g -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFLAG) $(NAME) $(OBJ) $(CFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re