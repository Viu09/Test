##
## EPITECH PROJECT, 2023
## panoramix [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

NAME	=	panoramix

SRC		=	src/main.c				\
			src/usefull.c			\
			src/villager_thread.c	\
			src/druid_thread.c

CFLAGS	=	-Wextra -Wall -pthread -g3

OBJ		=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
