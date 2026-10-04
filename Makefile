##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
## File description:
## Makefile
##

NAME	=	amazed

LIB = -L./lib/my -lmy

CFLAGS = -g

SRC	=	src/main.c \
		src/amazed.c \
		src/model.c \
		src/move.c \
		src/way.c \
		src/laby.c \
		src/find_way.c \
		src/disp_way.c \
		src/disp_move.c \
		src/error/free.c \
		src/error/handling.c \
		src/error/parsing.c \
		src/error/rooms.c \
		src/error/supp.c \
		src/error/clean.c	\

all:
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(LIB) -g

clean:
	make -C lib/my clean

fclean:
	make -C lib/my fclean
	rm -f vgcore.*
	rm -f coding-style-reports.log
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
