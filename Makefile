##
## EPITECH PROJECT, 2023
## B-NWP-400-PAR-4-1-myftp-laetitia.bousch
## File description:
## Makefile
##

SRC			=	src/main.c			\
				src/funct_verif.c	\
				src/funct_village.c	\
				src/funct_villager.c\
				src/funct_druid.c	\
				src/funct_free.c	\
				src/init_struct.c	\
				src/print_text.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	panoramix

CFLAGS		=	-Wall -Wextra -lpthread

CPPFLAGS	=	-iquote ./include

CC			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

./PHONY: all clean fclean
