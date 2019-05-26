##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the 42sh
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
		lib/str_to_word_tab_limited.c\
		src/main.c\
		src/main_loop.c\
		src/body_semic.c\
		src/directory.c\
		src/ctrlc.c\
		src/env.c\
		src/check_exist.c\
		src/semicolon.c\
		src/separators.c\
		src/basic_list.c\
		src/modif_env.c\
		src/path.c\
		src/manage_env_param.c\
		src/input.c\
		src/pipe.c\
		src/manage_cd.c\
		src/parse_pipe.c\
		src/exec_and.c\
		src/exec_or.c\
		src/seg_fault.c\
		src/history.c\
		src/redirections.c\
		src/display_history.c

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