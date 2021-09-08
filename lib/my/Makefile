##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c						\
		my_put_nbr.c 						\
		my_putstr.c  						\
		my_strcmp.c							\
		my_strcpy.c							\
		my_strcat.c 						\
		my_strlen.c  						\
		my_perror.c 						\
		my_atoi.c 							\
		my_str_to_word_array.c				\
		my_putarr.c 						\
		my_str_is_num.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -Wshadow -I ../../include

NAME	=	libmy.a

all:		 $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
