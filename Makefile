##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile 1
##

SRC	=	main.c				\
		analyse_events.c	\
		close_window.c		\
		destroy.c			\
		display_score.c		\
		duck.c				\
		game_over.c			\
		init.c				\
		lives.c				\
		menu.c				\
		move_rect.c			\
		options.c			\
		render.c			\
		sprite_utils.c		\
		sound.c				\
		lib/mini_printf.c	\
		lib/my_nbrtostr.c	\
		lib/my_putchar.c	\
		lib/my_putnbr.c		\
		lib/my_putstr.c		\
		lib/my_revstr.c		\
		lib/my_strcat.c		\
		lib/my_strcmp.c		\
		lib/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra \
	-l csfml-graphics -l csfml-system -l csfml-audio

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all
