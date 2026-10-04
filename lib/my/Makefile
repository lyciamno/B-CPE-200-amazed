##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
	    my_putchar.c \
	    my_strncmp.c	\
	    my_put_nbr.c \
	    my_putstr.c	\
	    my_strlen.c	\
	    my_strcat.c	\
	    my_strcmp.c	\
	    my_strcpy.c	\
		my_printf/my_printf.c \
		my_printf/flag.c \
		my_printf/flag_2.c \
		my_printf/flag_3.c 	\
		my_printf/hexa.c \
		my_printf/function_put.c \
		my_printf/function_science.c \

OBJ	=	$(SRC:.c=.o)

NAME	= 	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
