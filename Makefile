##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC	=	lib/my_putchar.c\
		lib/my_putstr.c\
		lib/my_put_nbr.c\
		lib/my_strlen.c\
		lib/my_printf.c\
		lib/my_getnbr.c\
		lib/my_strcat.c\
		lib/my_putnbr_base.c\
		lib/my_putstr_modif.c\
		lib/my_str_to_word_array.c\
		lib/my_strcmp.c\
		lib/my_strcpy.c\
		src/main.c\
		src/directory.c\
		src/ctrlc.c\
		src/env.c\
		src/check_exist.c\
		src/basic_list.c\
		src/modif_env.c

OBJ 	=	$(SRC:.c=.o)

NAME =  42sh

CFLAGS += -W -Wall -Wextra -pedantic -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo "Compiling..."
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o : %.c
		@echo "Compiling $@..."
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "removing *.o..."
	@rm -f lib/*.o
	@rm -f src/*.o
	@rm -f *.o

fclean:	clean
	@echo "removing $(NAME)..."
	@rm -f $(NAME)

re: 	fclean all

debug:	CFLAGS += -g3
debug:	fclean all