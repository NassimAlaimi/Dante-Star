##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	main.c 						\
		check_error.c				\
		utils.c 					\
		solve.c 					\
		final_path.c 				\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-Werror -Wextra -Wshadow -I ../include

LIB 	= 	-L ../lib/my -lmy

all:		 $(NAME)

$(NAME):	$(OBJ)

	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	rm -f ../lib/my/*.o
	rm -f ../src/*.o

fclean: clean
	rm -f $(NAME)
	rm -f ../lib/my/libmy.a

re:	fclean all
