##
## EPITECH PROJECT, 2020
## minishell
## File description:
## Makefile
##

SRC	=	main.c		\

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean	all