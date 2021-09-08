##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

SRC			=		src/main.c 				\
					src/check_error.c		\
					src/make_map.c			\
					src/malloc.c			\
					src/print.c				\
					src/destroy_wall.c		\
					src/my_show_int_tab.c	\
					src/do_wall.c			\
					src/imperfect_maze.c		
		
OBJ 		= 		$(SRC:.c=.o)

NAME 		=		generator

CFLAGS 		= 		-I./include 

LIB 		=		-L ../lib/my -lmy

CC			= 		gcc

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C ../lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		$(RM) -f $(OBJ)
		$(RM)  -f lib/my/*.o

fclean:		clean
		$(RM) -f $(NAME) *.gc*
		$(RM) -f $(NAME)

re: 	fclean all
