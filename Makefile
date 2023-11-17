##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile 1
##

SRC	=	main.c				\
		analyse_events.c	\
		move_rect.c			\
		render.c			\
		init.c				\
		close_window.c		\
		display_score.c		\
		lib/mini_printf.c	\
		lib/my_nbrtostr.c	\
		lib/my_putchar.c	\
		lib/my_putnbr.c		\
		lib/my_putstr.c		\
		lib/my_revstr.c		\
		lib/my_strcat.c		\
		lib/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra \
	-l csfml-graphics -l csfml-system

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all
