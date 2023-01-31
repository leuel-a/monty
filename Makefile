# -*- MakeFile -*-
# Constants
# ==============================================
CC = gcc
SRC = main.c splitString.c findFunction.c push.c pall.c
OBJ = $(SRC:.c=.o)
NAME = school
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

# Rules
# ==============================================
.PHONY: all clean oclean fclean re

all: monty.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean
