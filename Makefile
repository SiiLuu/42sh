##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
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

OBJ	=	$(SRC:.c=.o)

CFLAGS += -W -Wall -pedantic -Wextra -g3

NAME =  42sh

all: 	$(NAME)

$(NAME): 	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f *.o
	rm -f src/*.o
	rm -f lib/*.o

fclean: clean
	rm -f $(NAME)

re: 	fclean all
