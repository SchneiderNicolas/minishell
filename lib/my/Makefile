##
## EPITECH PROJECT, 2020
## minishell
## File description:
## Makefile lib
##

SRC	=	my_strlen.c			\
		my_putstr.c			\
		my_putchar.c		\
		my_putnbr.c			\
		my_puterr.c			\
		my_getnbr.c			\
		my_intlen.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_swapchar.c		\
		my_str_to_tab.c		\
		input.c				\
		my_strcmp.c			\
		init_linked_list.c	\
		my_strcmp_equal.c	\
		delete_node.c		\
		insert_node_end.c	\
		my_rev_list.c		\
		print_linked_list.c	\
		cd.c				\
		tab_len.c			\
		is_num.c			\
		my_env.c			\
		my_exit.c			\
		my_setenv.c			\
		is_letter.c			\
		my_isalnum.c		\
		get_user.c			\
		manage_pwd.c		\
		my_exec.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
	cp struct.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm ../$(NAME)

re:	fclean	all